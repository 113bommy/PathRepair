from math import ceil
n=int(input())
a=list(map(int,input().split()))
for i in range(n):
    a[i]=ceil((a[i]-i)/n)
print(a)
mini=min(a)
print(a.index(mini)+1)