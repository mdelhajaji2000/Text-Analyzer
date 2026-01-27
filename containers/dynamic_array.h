/*
_data ────────────┐
                  ↓
[ e0 ][ e1 ][ e2 ] ... [ eN-1 ][  end  ]
^                                   ^
begin()                          end()
*/



#pragma once
#include <stdexcept>

namespace STL_type
{
    template <typename T>
    class arr
    {
    public:
        using iterator = T*;
        using const_iterator = const T*;

    private:
        T*  _data;
        int _size;
        int _capacity;

        // Helper methodes : 
        void _Copying(T* dest, int from, int to)
        {
            if (dest != nullptr)
            for (int i = from; i < to; ++i)
                *(dest + i) = *(_data + i);
        }

    public:
        arr() noexcept
            : _data(nullptr), _size(0), _capacity(0)
        {}

        explicit arr(int init_size) noexcept
            : _data(init_size > 0 ? new T[init_size] : nullptr),
              _size(init_size),
              _capacity(init_size)
        {}

        ~arr()
        {
            delete[] _data;
        }

        arr(const arr& other)
            : _data(nullptr), _size(other._size), _capacity(other._capacity)
        {
            if (_size > 0)
            {
                _data = new T[_capacity];
                for (int i = 0; i < _size; ++i)
                    *(_data + i) = *(other._data + i);
            }
        }

        arr(arr&& other) noexcept
            : _data(other._data), _size(other._size), _capacity(other._capacity)
        {
            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }

        arr& operator=(const arr& other)
        {
            if (this == &other)
                return *this;

            T* new_data = nullptr;

            if (other._size > 0)
            {
                new_data = new T[other._capacity];
                for (int i = 0; i < other._size; ++i)
                    *(new_data + i) = *(other._data + i);
            }

            delete[] _data;
            _data = new_data;
            _size = other._size;
            _capacity = other._capacity;

            return *this;
        }

        arr& operator=(arr&& other) noexcept
        {
            if (this == &other)
                return *this;

            delete[] _data;

            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;

            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;

            return *this;
        }

        T& operator[](int index)
        {
            return *(_data + index);
        }

        const T& operator[](int index) const
        {
            return *(_data + index);
        }

        T& at(int index)
        {
            if (index < 0 || index >= _size)
                throw std::out_of_range("arr::at");

            return *(_data + index);
        }

        const T& at(int index) const
        {
            if (index < 0 || index >= _size)
                throw std::out_of_range("arr::at");

            return *(_data + index);
        }

        int size() const noexcept
        {
            return _size;
        }

        bool empty() const noexcept
        {
            return _size == 0;
        }

        int Capacity() const noexcept
        {
            return _capacity;
        }

        bool IsFull() const noexcept
        {
            return !(_capacity - _size);
        }

        void reserve(int size_to_reserve)
        {
            if (size_to_reserve <= _capacity)
                return;

            T* __data = new T[size_to_reserve];
            _Copying(__data, 0, _size);

            delete[] _data;
            _data = __data;
            _capacity = size_to_reserve;
        }

        T& front() noexcept
        {
            return *(_data);   
        }

        const T& front() const noexcept
        {
            return *(_data);
        }

        T& back() noexcept
        {
            return *(_data + _size - 1);
        }

        const T& back() const noexcept
        {
            return *(_data + _size - 1);
        }

        void shrink_to_fit()
        {
            if (_capacity == _size)
                return;

            T* __data = new T[_size];
            _Copying(__data, 0, _size);

            delete[] _data;
            _data = __data;
            _capacity = _size;
        }

        void push_back(const T& value)
        {
            if (_size < _capacity)
            {
                *(_data + _size) = value;
                _size++;
                return;
            }

            if (_capacity == 0) _capacity++;
            T* __data = new T[_capacity * 2];
            _Copying(__data, 0, _size);
            *(__data + _size) = value;

            delete[] _data;
            _data = __data;
            ++_size;
            _capacity *=2;
        }

        void pop_back() noexcept
        {
            if (_size == 0)
                return;

            _size--;
        }

        void insert(int index, const T& value)
        {
            if (index < 0 || index > _size)
                throw std::out_of_range("index out of range");

            if (_size < _capacity)
            {
                for (int i = _size; i > index; i++)
                    *(_data + i) = *(_data + i - 1);

                *(_data + index) = value;
                ++_size;
                return;
            }

            int new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
            T* __data = new T[new_capacity];

            _Copying(__data, 0, index);
            *(__data + index) = value;

            for (int i = index; i < _size; ++i)
                *(__data + i + 1) = *(_data + i);

            delete[] _data;
            _data = __data;
            _capacity = new_capacity;
            ++_size;

        }

        void erase(int index)
        {
            if (index >= _size || index < 0)
                throw std::out_of_range("index out of range");

            for (int i = index; i < _size - 1; i++)
            {
                *(_data + i) = *(_data + i + 1);
            }

            --_size;
        }

        iterator begin() noexcept
        {
            return _data;
        }

        iterator end() noexcept
        {
            return _data + _size;
        }

        const_iterator begin() const noexcept
        {
            return _data;
        }

        const_iterator end() const noexcept
        {
            return _data + _size;
        }

        const_iterator cbegin() const noexcept
        {
            return _data;
        }

        const_iterator cend() const noexcept
        {
            return _data + _size;
        }

        iterator erase(iterator first, iterator last)
        {
            if (first < begin() || last > end() || first > last)
                throw std::out_of_range("invalid itrerator range");

            int start = first - begin();
            int count = last - first;

            if (count == 0)
                return first;

            for (int i = start; i < _size - count; ++i)
            {
                *(_data + i) = *(_data + i + count);
            }

            _size -= count;
            return _data + start;
        }

        iterator insert(iterator pos, const T& value)
        {
            if (pos < begin() || pos > end())
                throw std::out_of_range("iterator out of range");

            int index = pos - begin();
            insert(index, value);

            return _data + index;
        }

        void Clear() noexcept
        {
            _size = 0;
        }

        T* Data() noexcept
        {
            return _data;
        }

        const T* Data() const noexcept
        {
            return _data;
        }

    };
}
