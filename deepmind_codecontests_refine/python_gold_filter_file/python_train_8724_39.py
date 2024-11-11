n,m=map(int,input().split())
l=set(range(1,m+1))
for i in range(n):
    k,*a=map(int,input().split())
    l&=set(a)
print(len(l))