t = int(input())
for _ in range(t):
    a,b,n= map(int,input().split())
    c=0
    while a<n and b<n:
        if a>b:
            b+=a
        else:
            a+=b
        c+=1
    print(c)







