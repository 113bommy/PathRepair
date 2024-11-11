def sum(a,x,n):
    l=0
    r=0
    for i in range(x):
        l=l+int(a[i])
    for i in range(x,n):
        r=r+int(a[i])
    return l==r
n=int(input())
x=list(input())
flag=0
for i in range(len(x)):
    if x[i]!='4' and x[i]!='7':
        print("NO")
        flag=1
        break
if flag!=1:
    if sum(x,n//2,n)==1:
        print("YES")
    else:
        print("NO")