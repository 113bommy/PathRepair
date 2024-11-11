
def Same_GCDs(a, m):
    d = MCD(a, m) 
 
    return Phi(m // d)


def MCD(a, b):
    if b == 0:
        return a
    
    else:
        return MCD(b, a % b)


def Descomp_En_Primos(n): 
    factPrimos = []

    if n % 2 == 0: 
        exp = 0

        while n % 2 == 0:
            n //= 2 
            exp += 1 
        
        factPrimos.append((2, exp))

    for i in range(3, n + 1, 2): 

        # if Es_Primo(n):
        #     factPrimos.append((n, 1))
        #     break

        if i * i > n: 
            factPrimos.append((n, 1))
            break

        if n % i == 0: # and Es_Primo(i):
            exp = 0

            while n % i == 0:
                n //= i
                exp += 1 
            
            factPrimos.append((i, exp))

            if n == 1:
                break  
        
    return factPrimos


def Es_Primo(n): 
    if n == 2:
        return True

    for i in range(2, int(n ** 1/2) + 1): 
        if n % i == 0:
            return False
    
    return True

def Phi(n):
    factores_primos = Descomp_En_Primos(n)
    
    phi = n

    for i in range(0, len(factores_primos)):
        phi = phi - phi // factores_primos[i][0] 
    return phi


t = int(input())

while t > 0:
    _input = [int(x) for x in input().split()]

    a = _input[0]
    m = _input[1]

    print(Same_GCDs(a, m))

    t -= 1
