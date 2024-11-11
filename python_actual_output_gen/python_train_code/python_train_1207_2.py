n,m=map(int,input().split())
s=str(input())
for i in range(m):
    p=""
    l,r,c1,c2=input().split()
    l,r=[int(l),int(r)]
    c1,c2=[str(c1),str(c2)]
    for j in range(n):
        if(s[j]==c1 and l<=j+1 and r>=j+1):
            p=p+c2
        else:
            p=p+s[j]
    s=p
    print(s)    
