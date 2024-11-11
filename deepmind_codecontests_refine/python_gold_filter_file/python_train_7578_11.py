# E

# 入力
# input
N = int(input())
a_list = [0]*(N+1)
for i in range(N+1):
    a_list[N-i] = int(input())


# 10^5までの素数を計算
# list primes <= 10^5 
primes = list(range(10**5))
primes[0] = 0
primes[1] = 0
for p in range(2, 10**5):
    if primes[p]:
        for i in range(2*p, 10**5, p):
            primes[i] = 0
primes = [p for p in primes if p>0]
# primes <= N
p_list_small = [p for p in primes if p <= N]


# A_Nを素因数分解、Nより大きい素因数をp_list_largeに追加
# A_N, ..., A_0の最大公約数の素因数でやっても同じ
# list prime factors of A_N, if greater then N, add to p_list_large
# you can use prime factors of gcd(A_N, ..., A_0) instead 

p_list_large = []
A = abs(a_list[-1])
for p in primes:
    if A % p == 0:
        if p > N:
            p_list_large.append(p)
        while A % p == 0:
            A = A // p
if A != 1:
    p_list_large.append(A)

# 個別に条件確認
# check all p in p_list_small
# x^p ~ x (mod p)
res_list = []
for p in p_list_small:
    r = 0
    check_list = [0]*(N+1)
    for i in range(p):
        check_list[i] = a_list[i]
    for i in range(p, N+1):
        check_list[(i-1) % (p-1) + 1] += a_list[i]
    for i in range(p):
        if check_list[i] % p != 0:
            r = 1
    if r == 0:
        res_list.append(p)
        
# 個別に条件確認
# check all p in p_list_large
# a_i % p == 0
for p in p_list_large:
    r = 0
    for i in range(N+1):
        if a_list[i] % p != 0:
            r = 1
    if r == 0:
        res_list.append(p)
        
for p in res_list:
    print(p)