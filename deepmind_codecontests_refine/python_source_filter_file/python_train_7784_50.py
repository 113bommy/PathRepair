N, M = map(int, input().split())
l = N
r = 1
for i in range(M):
    if N%4==0 and i*2==N: r+=1
    elif N%2==0 and l-r==N//2: r+=1
    print(l, r)
    l-=1
    r+=1
