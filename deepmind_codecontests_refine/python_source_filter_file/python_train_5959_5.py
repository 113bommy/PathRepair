m,n,k=map(int,input().split())
s='U'*(m-1)+'L'*(n-1)
c=0
for i in range(n):
    if c==0:
        s+='R'*(m-1)+'D'
        c=1
    else:
        c=0
        s+='L'*(m-1)+'D'
print(m*n+m+n-3)
print(s[:m*n+m+n-3])