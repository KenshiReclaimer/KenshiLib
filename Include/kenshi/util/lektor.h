#pragma once

namespace Kenshi
{
    template <typename T>
    class lektor
    {
    public:

            typedef       T* iterator;
            typedef const T* const_iterator;

            iterator       begin()       { return m_heap; }
            const_iterator begin() const { return m_heap; }
            iterator       end()         { return m_heap + m_length; }
            const_iterator end()   const { return m_heap + m_length; }

            T& at(uint32_t index) {
                assert(m_heap && index < m_length);
                return m_heap[index];
            }

            T& operator[](uint32_t index) {
                return at(index);
            }

            const T& operator[](uint32_t index) const {
                assert(m_heap && index < m_length);
                return m_heap[index];
            }

            bool valid() const { return m_heap != nullptr; }
            void clear() { m_length = 0; }

            uint32_t size()     const { return m_length; }
            uint32_t capacity() const { return m_capacity; }

            T& find_first(bool* found, bool(*cmpfn)(T&))
            {
                for (uint32_t i = 0; i < m_length; ++i) {
                    if (cmpfn(m_heap[i])) {
                        return m_heap[i];
                    }
                }
            }


    private:
        uint32_t m_length;
        uint32_t m_capacity;
        T* m_heap;

        virtual ~lektor();
    };
}