n,m=map(int,input().split())
k=0
for i in range(n):
    x,y=map(str,input().split())
    if x=='-':
        if m>int(y):
            m=m-int(y)
        else:
            k=k+1
    else:
        m=m+int(y)
print(m,k)