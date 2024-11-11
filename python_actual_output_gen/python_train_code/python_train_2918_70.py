a,b=map(int,input().split())
if a==b:
    print(a,0)
elif a>b:
    print(b,a//2)
else:
    print(a,b//2)