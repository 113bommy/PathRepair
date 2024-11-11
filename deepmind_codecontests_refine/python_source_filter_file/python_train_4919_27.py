n,s=map(int,input().split())
k=1
if s-(n-1)*2<2:
    print("NO")
else:
    print("YES")
    d=[s-(n-1)*2]
    for i in range(n):
        d.append(2)
    print(*d)
    print(k)
    
