t=int(input())
res=[]
while t:
    n=int(input())
    a=list(map(int,input().split(" ")))[:n]
    b=list(map(int,input().split(" ")))[:n]
    diff=0
    for i in range (n):
        if a[i]-b[i] != 0:
            diff=abs(a[i]-b[i])
            break
    flag=0
    l=0
    r=0
    for i in range (n):
        if a[i] != b[i] and flag==0:
            l=i
            flag=1
        elif a[i] != b[i] and flag==1:
            r=i
    if l == n:
        r=l
    for i in range (l,r+1):
        a[i]+=diff
    flag=1
    for i in range (n):
        if a[i] != b[i] :
            flag=0
            break
    res.append(flag)
    t-=1
for flag in res:
    if flag==1:
        print("YES")
    else:
        print("NO")
    

