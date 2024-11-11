n,m,k=map(int,input().split())
A=list(map(int,input().split()))
A.sort()
max = A[-1]
min = A[-2]

if m % (k + 1) == 0:
    t = m // (k + 1)
    an = t * k * max + t * min
    print(an)
else:
    t = m // (k + 1)
    an = t * k * max + t * min
    an += (m % (m + 1)) * max
    print(an)
        