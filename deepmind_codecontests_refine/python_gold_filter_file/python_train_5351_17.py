n,m=list(map(int,input().split()))
l=[]
k=0
for _ in range(n):
    s=input()
    if 'S' not in s:
        k+=1
    l.append(s)
if k==n:
    print(n*m)
else:
    k1=0
    for i in range(m):
        s=''
        for j in range(n):
            s+=l[j][i]
        if 'S' not in s:
            k1+=1
    
    print(k*m+k1*n) if k==0 or k1==0 else print(k*m+k1*n-k*k1)
