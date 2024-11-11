a,b=map(int,input().split())
if a>=b:
    k=b
    m=a//2
elif a<b:
    k=a
    m=b//2
print(k,m)
        