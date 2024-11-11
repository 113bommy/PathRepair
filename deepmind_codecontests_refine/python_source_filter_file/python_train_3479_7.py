from heapq import heappop,heappush
n=int(input())
a,b,c=[],[],[]
for i in input().split():
    heappush(a,int(i))
for i in range(n):
    m=str(heappop(a))
    if b and b[-1]==m:
        if not c or c[-1]!=m:
            c.insert(0,m)
    else:
        b+=[m]
if c and b and c[0]==b[-1]:
    c.pop(0)
print(len(b)+len(c))
print(' '.join(b+c))
