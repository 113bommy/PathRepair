def f(s,p):
    p.append(s.pop(0))
    for i,num in enumerate(s):
        if num % p[-1] == 0:
            s.pop(i)
    return 0

def vol44(k):
    for i in range(len(p)):
        if p[i] == k:
            print(p[i-1],p[i+1])
            break
        elif p[i] > k:
            print(p[i-1],p[i])
            break

primes = list(range(2,50000))
arr = []
while not arr or arr[-1] ** 2 < primes[-1]:
    f(primes,arr)
p = arr+primes

n = []
while True:
    try:
        n.append(int(input()))
    except EOFError:
        break

for i in range(len(n)):
    vol44(n[i])