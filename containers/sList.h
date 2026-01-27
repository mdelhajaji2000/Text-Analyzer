#pragma once

#include <cstddef>

namespace STL_type
{
    template <typename T>
    class sList
    {
        private:
            struct _node
            {
                T _data;
                _node* _next;

                _node(const T& value, _node* next = nullptr) noexcept
                    : _data(value), _next(next)
                {}
            };

            _node* _head;
            _node* _tail;
            std::size_t _size;

        public:

        class iterator
        {
            private:
                _node* _curr;

            public:
                iterator(_node* p = nullptr) noexcept : _curr(p) {}

                T& operator*() const noexcept
                {
                    return _curr->_data;
                }

                iterator& operator++() noexcept
                {
                    _curr = _curr->_next;
                    return *this;
                }

                bool operator==(const iterator& other) const noexcept
                {
                    return _curr == other._curr;
                }

                bool operator!=(const iterator& other) const noexcept
                {
                    return _curr != other._curr;
                }

            friend class sList;
        };

        class const_iterator
        {
            private:
                _node* _curr;

            public:
                const_iterator(_node* p = nullptr) noexcept : _curr(p) {}
                const_iterator(const iterator& it) noexcept : _curr(it._curr) {}

                const T& operator*() const noexcept
                {
                    return _curr->_data;
                }

                const_iterator& operator++() noexcept
                {
                    _curr = _curr->_next;
                    return *this;
                }

                bool operator==(const const_iterator& other) const noexcept
                {
                    return _curr == other._curr;
                }

                bool operator!=(const const_iterator& other) const noexcept
                {
                    return _curr != other._curr;
                }


            friend class sList;
        };

            iterator begin() noexcept
            {
                return iterator(_head);
            }

            const_iterator cbegin() const noexcept
            {
                return const_iterator(_head);
            }

            iterator end() noexcept
            {
                return iterator(nullptr);
            }

            const_iterator cend() const noexcept
            {
                return const_iterator(nullptr);
            }

            iterator insert_after(iterator it_pos, const T& value)
            {
                _node* curr = it_pos._curr;
                if (!curr)
                    return end();
                _node* new_node = new _node(value);
                new_node->_next = curr->_next;
                curr->_next = new_node;
                _size++;

                if (_tail == curr)
                    _tail = new_node;

                return iterator(new_node);
            }
            
            iterator erase_after(iterator it_pos)
            {
                _node* curr = it_pos._curr;

                if (!curr || !curr->_next)
                    return end();

                _node* node_to_erase = curr->_next;

                if (node_to_erase->_next == nullptr)
                    _tail = curr;

                curr->_next = node_to_erase->_next;
                delete node_to_erase;

                _size--;

                return iterator(curr->_next);
            }

            ~sList()
            {
                clear();
            }

            sList() noexcept : _head(nullptr), _tail(nullptr), _size(0) {}

            sList(const sList& other) : _head(nullptr), _tail(nullptr), _size(0)
            {
                if (!other._head)
                    return;

                _head = new _node(other._head->_data);
                _node* _curr_this = _head;
                _node* _curr_other = other._head->_next;

                while (_curr_other)
                {
                    _curr_this->_next = new _node(_curr_other->_data);

                    _curr_this = _curr_this->_next;
                    _curr_other = _curr_other->_next;
                }
                _tail = _curr_this;
                _size = other._size;
            }

            sList(sList&& other) noexcept
                : _head(other._head),
                  _tail(other._tail),
                  _size(other._size)
            {
                other._head = nullptr;
                other._tail = nullptr;
                other._size = 0;
            }

            sList& operator=(sList&& other) noexcept
            {
                if (this == &other)
                    return *this;

                clear();
                _head = other._head;
                _tail = other._tail;
                _size = other._size;
                other._head = nullptr;
                other._tail = nullptr;
                other._size = 0;

                return *this;
            }

            sList& operator=(const sList& other)
            {
                if (this == &other)
                    return *this;

                clear();

                if (!other._head)
                    return *this;

                _head = new _node(other._head->_data);
                _node* _curr_this = _head;
                _node* _curr_other = other._head->_next;

                while (_curr_other)
                {
                    _curr_this->_next = new _node(_curr_other->_data);
                    _curr_this = _curr_this->_next;
                    _curr_other = _curr_other->_next;
                }

                _tail = _curr_this;
                _size = other._size;
                return *this;
                
            }

            std::size_t size() const noexcept
            {
                return _size;
            }

            void clear()
            {
                _node* _curr = _head;
                while (_curr)
                {
                    _node* temp = _curr;
                    _curr = _curr->_next;
                    delete temp;
                }
                
                _head = nullptr;
                _tail = nullptr;
                _size = 0;
            }

            bool empty() const noexcept
            {
                return _size == 0;
            }

            T& front() noexcept
            {
                return _head->_data;
            }

            const T& front() const noexcept 
            {
                return _head->_data;
            }

            void push_front(const T& value)
            {
                _node* node = new _node(value, _head);
                _head = node;
                ++_size;
            }

            void pop_front()
            {
                if (_size == 0)
                    return;
                
                _node* temp = _head;
                _head =  _head->_next;
                delete temp;
                --_size;
            }

            void push_back(const T& value)
            {
                _node* new_node = new _node(value, nullptr);

                if (_size == 0)
                {
                    _head = new_node;
                    _tail = new_node;
                }
                else
                {
                    _tail->_next = new_node;
                    _tail = new_node;
                }

                ++_size;
            }

            void pop_back()
            {
                if (_size == 0)
                    return;

                if (_size == 1)
                {
                    clear();
                    return;
                }
                
                _node* curr = _head;
                while (curr->_next != _tail)
                {
                    curr = curr->_next;
                }
                
                delete _tail;
                curr->_next = nullptr;
                _tail = curr;
                --_size;
            }
    };
}
