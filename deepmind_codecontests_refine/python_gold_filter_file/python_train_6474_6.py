n, m = [int(i) for i in input().split()]


N = 1000000007; 
      
def exponentiation(bas, exp): 
    if (exp == 0): 
        return 1; 
    if (exp == 1): 
        return bas % N; 
      
    t = exponentiation(bas, int(exp / 2)); 
    t = (t * t) % N; 
      
 
    if (exp % 2 == 0): 
        return t; 
          
 
    else: 
        return ((bas % N) * t) % N;

modulo = exponentiation(2, m) - 1
print(exponentiation(modulo, n))

