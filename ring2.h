#ifndef RING2_H_
#define RING2_H_

#include <initializer_list>
#include <iostream>

template<typename T>
class ring2 {
    public:
    class iterator;
    public:
        ring2(int n) : m_pos{0}, m_size{n}, m_values{new T[n]} {}
        ring2(std::initializer_list<T> l) 
            // : m_pos{0}, m_size {l.data().size()}, m_values{new T[m_size]} 
            {
                m_pos=0;
                m_size= l.size();
                m_values=new T[m_size];

                // for(int i{0}; i< m_size; ++i) {
                //     m_values[i]=data(l)[i];
                // } 
                int cnt=0; for (auto i : l) m_values[cnt++]=i;

            }

        void add(T t) {
            m_values[m_pos++] = t;
            if(m_pos == m_size) m_pos = 0;
        }
        int size() { return m_size; }
        T& get(int i) { 
            if (i < m_size)
                return m_values[i];
            return m_values[0];
        }
        iterator begin();
        iterator end();

    private:
        int m_pos;
        int m_size;
        T *m_values;
};

template<typename T>
typename ring2<T>::iterator ring2<T>::begin() { return ring2<T>::iterator(0, *this); }

template<typename T>
typename ring2<T>::iterator ring2<T>::end() { return ring2<T>::iterator(m_size, *this); }


template<typename T>
class ring2<T>::iterator {
    public:
        iterator(int pos, ring2& ring) : it_pos{pos}, it_ring{ring} {}

        bool operator!=(const ring2<T>::iterator other) const;
        iterator operator++(); // prefix
        iterator operator++(int); //postfix
        T& operator*();

    private:
        int it_pos;
        ring2<T>& it_ring;
};

template<typename T>
bool ring2<T>::iterator::operator!=(const ring2<T>::iterator other) const {
    return it_pos != other.it_pos;
}

template<typename T>
typename ring2<T>::iterator ring2<T>::iterator::operator++() {
    it_pos++;
    return *this;
}

template<typename T>
typename ring2<T>::iterator ring2<T>::iterator::operator++(int) {
    ring2<T>::iterator temp = *this; // making a copy
    it_pos++;
    return temp;
}

template<typename T>
T& ring2<T>::iterator::operator*() { return it_ring.get(it_pos); }

#endif // RING2_H_