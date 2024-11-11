import math

def f_k_n(n,k):
    k = (k+1)/2
    while n>1 and k:
	    n = phi_improved(n)
	    k =k-1
    return n
    
def f(n):
    return phi_improved(n)

def phi_improved(n):
    prime_fact = find_prime_factors(n)
    result = n
    for p in prime_fact:
        result *= 1 - (1/p)
    return int(result)
        
def find_prime_factors(n):
    l = []
    temp_n = n
    if temp_n % 2 == 0:
        l.append(2)
    while temp_n % 2 == 0:#mientras sea divisible por 2 lo divido hasta que sea impar
        temp_n = temp_n / 2
    i = 3
    last_i = 0
    while i <= math.sqrt(n):#busco hasta la raiz los factores de la descomposicion en primos
        if temp_n % i == 0:
            if last_i != i: 
                l.append(i)
                last_i = i
            temp_n = temp_n / i
        else: 
            i += 2
    if temp_n > 2:# ya no tiene mas divisores entonces es primo y no se ha agregado a la lista
        l.append(int(temp_n))
    return  l



def main():
    n,k = [int(i) for i in input().split()]
    print(str(f_k_n(n,k) % 1000000007))

main()
