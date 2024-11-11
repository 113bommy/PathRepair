n = int(input())
if n & 1:
    print(-1)
else:
    k=2
    s=[0]*n
    for i in range(n):
        if not i & 1:
            s[i]=k
            k-=1
        else:
            s[i]=k
            k+=3
    print(s)
        
        
        
        