n=int(input())
l=list(map(int,input().split()))
b=sum(l)**2
a=0
for i in range(n):
    a+=l[i]**2
print((b-a)%(10**9+7)//2)