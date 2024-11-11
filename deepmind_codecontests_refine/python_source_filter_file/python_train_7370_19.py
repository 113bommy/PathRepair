from collections import Counter
n=int(input())
b=[tuple(map(int,input().split())) for _ in range(n)]
r=[(x[0]-y[0],x[1]-y[1]) for x in b for y in b if x!=y]
c=Counter(r).most_commom(1)
print(n-c[0][1] if c else n)