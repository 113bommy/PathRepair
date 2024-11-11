n=int(input())
*a,=map(int,input().split())
m=sum(a)/n
print(m)
i=0
s=10**18
for j in range(n):
    if abs(a[j]-m)<s:
        i=j
        s=abs(a[j]-m)
print(i)