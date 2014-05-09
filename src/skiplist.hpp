#ifndef SKIP_LIST
#define SKIP_LIST

#include <stdlib.h>
#include <assert.h>
#include "../deps/random.h"

namespace util{
    typedef int level_t;
    const level_t MAX_LEVEL = 16;

    template <typename TKey, typename TVal>
    class SkipList 
    {
        public:
            SkipList(const TKey& max): rand_(0x01bdfe8a)
            {
                init_(max);
            }

            ~SkipList()
            {
                Release();
            }

            bool Search(const TKey& key, TVal& val)
            {
                node_t* update[MAX_LEVEL];
                node_t* n;
                return hasNode_(key, val, &n, update);
            }

            bool Insert(const TKey& key, TVal& val)
            {
                node_t* update[MAX_LEVEL];
                node_t* n;
                if(!hasNode_(key, val, &n, update))
                {
                    level_t level = randomLevel_();
                    if(level > list_->level_)
                    {
                        //level = ++list_->level_;
                        int i;
                        for(i = list_->level_; i<= level; ++i)
                            update[i] = list_->header_;
                        list_->level_ = level;
                    }
                    node_t* newNode = newNode_(level);
                    newNode->key_ = key;
                    newNode->val_ = val;
                    int i = level;
                    for(;i >= 0; --i)
                    {
                        node_t* tempN = update[i];
                        newNode->forward_[i] = tempN->forward_[i];
                        tempN->forward_[i] = newNode;
                    }
                    return true;
                }
                return false;
            }

            bool Delete(const TKey& key, TVal& val)
            {
                node_t* update[MAX_LEVEL];
                node_t* n;
                if (hasNode_(key, val, &n, update))
                {
                    int i;
                    for(i = 0; i <= list_->level_; ++i)
                    {
                        if(update[i]->forward_[i] != n)
                        {
                            break;
                        }
                        update[i]->forward_[i] = n->forward_[i];
                    }
                    free(n);
                    while(list_->level_ > 0
                            && list_->header_->forward_[list_->level_] == nil_)
                    {
                        --list_->level_;
                    }
                }
                return true;
            }

            void Release()
            {
                node_t* n = list_->header_;
                while(n != nil_)
                {
                    node_t* tempN = n->forward_[0];
                    free(n);
                    n = tempN;
                }
                free(n);free(list_);
            }
            
        private:
            struct node_t
            {
                TKey key_;
                TVal val_;
                level_t level_;
                node_t* forward_[1];
            };
            struct list_t
            {
                level_t level_;
                node_t* header_;
            };

            list_t* list_;
            node_t* nil_;
            Random rand_;
        private:
            void init_(TKey max)
            {
                nil_ = (node_t*)malloc(sizeof(node_t));
                nil_->key_ = max;
                nil_->level_ = 0;
                list_ = (list_t*)malloc(sizeof(list_t));
                list_->level_ = 0;
                list_->header_ = newNode_(MAX_LEVEL);
                list_->header_->level_ = 0;
                int i;
                for(i = 0; i < MAX_LEVEL; ++i)
                {
                    list_->header_->forward_[i] = nil_;
                }
            }

            node_t* newNode_(const level_t level)
            {
                node_t* node = (node_t*)malloc(sizeof(node_t) + level*sizeof(node_t*));
                node->level_ = level;
                return node;
            }

            level_t randomLevel_()
            {
                static const unsigned int kBranching = 4;
                level_t height = 1;
                while(height < MAX_LEVEL && ((rand_.Next() % kBranching) == 0))
                {
                   height++; 
                }
                assert(height > 0);
                assert(height <= MAX_LEVEL);
                return height;
            }

            bool hasNode_(const TKey& key, TVal& val, node_t** node, node_t* update[MAX_LEVEL])
            {
                node_t* n = list_->header_;
                int i = list_->level_;
                for(; i>=0; --i)
                {
                    while(n->forward_[i]->key_ < key)
                    {
                        n = n->forward_[i];
                    }
                    update[i] = n;
                }
                if (n->forward_[0]->key_ != key)
                {
                    return false;
                }
                else
                {
                    val = n->forward_[0]->val_;
                    *node = n->forward_[0];
                    return true;
                }
            }
    };
};

#endif