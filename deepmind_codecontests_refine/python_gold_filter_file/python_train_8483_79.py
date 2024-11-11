a,b=map(int,input().split())
if a>=b:
    k=b
    m=(a-b)//2
elif a<b:
    k=a
    m=(b-a)//2
print(k,m)
        