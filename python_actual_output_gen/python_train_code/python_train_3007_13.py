n,m=map(int,input().split())
s=set(range(1,m+1))
for i in range(n):
    k,*a=map(int,input().split())
    s&=set(a)
print(les(s))
