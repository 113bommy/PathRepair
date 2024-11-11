n,m=map(int,input().split())
s=set(range(1,m+1))
for i in range(n):
    k,*a=list(map(int,input().split()))
    s&=set(a)
print(len(s))