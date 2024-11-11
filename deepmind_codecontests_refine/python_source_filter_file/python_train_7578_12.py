def p_factors(n):
    if n < 2:
        return []
    
    d = 2
    result = []
    while n > 1 and d*d <= n:
        if n % d == 0:
            result.append(d)
        while n % d == 0:
            n //= d
        d += 1
        
    if n > 1:
        # n is a prime
        result.append(n)
    return result

def sieve_of_eratosthenes(ub):
    # O(n loglog n) implementation.
    # returns prime numbers <= ub.
    if ub < 2:
        return []
    prime = [True]*(ub+1)
    prime[0] = False
    prime[1] = False
    p = 2
    while p*p <= ub:
        if prime[p]:
            # don't need to check p+1 ~ p^2-1 (they've already been checked).
            for i in range(p*p, ub+1, p):
                prime[i] = False
        p += 1
    return [i for i in range(ub+1) if prime[i]]

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a%b
    return a

def gcd_list(lst):
    if len(lst) == 0:
        return 0
    if len(lst) == 1:
        return lst[0]
    g = abs(lst[0])
    for l in lst[1:]:
        g = gcd(g, abs(l))
    return g

N = int(input())
A = [int(input()) for _ in range(N+1)]

cands = set(sieve_of_eratosthenes(N) + p_factors(gcd_list(A)))
answer = []
A = list(reversed(A))

for p in cands:
    flag = True
    # f(x) = Q(x) (x^p - x) + \sum_{i = 0}^{p-2} h_i x^i (mod p), 
    # where h_i = \sum_{j < N, j % (p-1) = i} a_j
    if A[0] % p != 0:
        flag = False
    else:
        for i in range(1, min(N, p-2) + 1):
            h = 0  
            j = i
            while j <= N:
                h = (h + A[j]) % p
                j += p - 1
            if h != 0:
                flag = False
                break
                
    if flag:
        answer.append(p)

if answer:
    answer = sorted(answer)
print(*answer, sep='\n')