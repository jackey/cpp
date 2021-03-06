#define PROBLEM_ONE 0

class Log_Addr
{
public:
    
#if PROBLEM_ONE    
    template <typename T>
    operator T *() const 
    { 
        return reinterpret_cast<T *>(_addr); 
    }
    
    // Quick and dirt solution:
    /* 
     operator int *() const 
     { 
         return reinterpret_cast<int *>(_addr); 
     }
    */ 
#endif

    /* A plausible solution. 
     * However it requires to replace all "static_cast" to "cast_to". 
     */
    template <typename T>
    T cast_to() const 
    { 
        return reinterpret_cast<T>(_addr); 
    }


private:
    unsigned int _addr;
};


int main()
{ 
    Log_Addr sp;
    
#if PROBLEM_ONE    
    static_cast<int *>(sp); // Question: how to specify that T is an int?
#endif

    // sp.foo(); // does not work even for g++
    sp.cast_to<int *>();
    
    *(sp.cast_to<int *>()) = 3;
    
    return 0;
}


