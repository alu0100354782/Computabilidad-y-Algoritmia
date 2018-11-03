#include "sorted_vector_t.hpp"

#include <limits>
#include <iomanip>

namespace CyA
{

void sorted_vector_t::merge_sort(void)
{
    // merge_sort(0, size() - 1); // recursivo
    merge_sort_iterative(0, size() - 1);
}

void sorted_vector_t::write(ostream& os) const
{
    const int sz = size();

    os << "< ";
    for(int i = 0; i < sz; i++)
        os << setw(5) << at(i);
    os << "> ";
}


void sorted_vector_t::merge_sort(int l, int r)
{
    if (l < r) {
        
        int c = (l + r) / 2;        

        // MODIFICACIÓN: Imprimir tamaño de los subvectores X e Y
        cout << "Tamaño vector X: " << c - l +1
             << "\tTamaño vector Y: " << r - c << endl;

        merge_sort(l, c);        

        merge_sort(c + 1, r);

        merge(l, c, r);
    }
}


////////////////////////////////////////////////////////////////////////////
// FUSIÓN CON CENTINELA
////////////////////////////////////////////////////////////////////////////

void sorted_vector_t::create_vector_sentinel(int l, int r, vector<int>& v)
{
    for (int i=l; i <= r; i++)
        v.push_back(at(i));
        
    v.push_back(numeric_limits<int>::max());
}

void sorted_vector_t::merge(int l, int c, int r)
{    
    vector<int> v_left, v_right;
    
    create_vector_sentinel(l, c, v_left);
    create_vector_sentinel(c+1, r, v_right);


    int l_index = 0, r_index = 0;

    for(int i = 0; i < r - l + 1; i++)
        if (v_left.at(l_index) < v_right.at(r_index))
            at(l + i) = v_left.at(l_index++);
        else
            at(l + i) = v_right.at(r_index++);
}

////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////
// FUSIÓN ITERATIVO
////////////////////////////////////////////////////////////////////////////
int sorted_vector_t::min(int x, int y) 
{ 
    return (x < y)? x : y;
}

void sorted_vector_t::merge_sort_iterative(int l, int r)
{
    int size = r-l+1;
    for(int curr_size = 1; curr_size <= size; curr_size *= 2) 
    {
        for (int l_index = 0; l_index < size; l_index += 2*curr_size)
        {
            int c = l_index + curr_size - 1;
            int r_end = min(l_index + 2*curr_size, size - 1);
            merge(l_index,c,r_end);
        }
    }
}

}
///////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& os, const CyA::sorted_vector_t& v)
{
    v.write(os);
    return os;
}
