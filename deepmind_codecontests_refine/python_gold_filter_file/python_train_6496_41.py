n,m=map(int,input().split())
L=list(map(int,input().split()))
s=0
j=1
for i in range(m):
    if L[i]<j :
        s+=(n-j)+L[i]
        j=L[i]
    else :
        s+=L[i]-j
        j=L[i]
print(s)
