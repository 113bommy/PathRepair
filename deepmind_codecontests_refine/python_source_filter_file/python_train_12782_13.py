import collections

x=int(input())
a=list(map(int,input().split()))

c=collections.Counter(a)
num=0
for i in c.values():
    num+=i*(i-1)/2
    
for i in range(x):
    print(num-c[a[i]]+1)