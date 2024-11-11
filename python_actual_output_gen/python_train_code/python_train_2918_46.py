m,n=map(int,input().split())
if m>=n:
    k=n
else:
    k=m
l=abs((m-n)//2)
print(k,l)
