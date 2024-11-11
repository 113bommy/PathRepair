a,b=map(int,input().split())
s=0
for C in range(a,b+1):
    C=str(C)
    c=C[::-1]
    s+=(C==c)
print(s)