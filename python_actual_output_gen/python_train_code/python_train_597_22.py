T = int(input())
for t in range(T):
    N = int(input())
    L = list(map(int,input().split()))
    m = L[-1]
    r = 0
    for n in range(1,N+1):
        if L[-n] > m:
            r = r + 1
        if L[-n] < m:
            m = L[-n]
print (r)
