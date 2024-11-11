n=int(input())
a=list((map(int,input().split())))
f=a.count(5)
z=a.count(0)
aa=f//9

if aa>=1 and z>=1:
    ans=""
    for i in range(aa):
        ans+="999999999"
    for i in range(z):
        ans+="0"
    print(ans)
else:
    if z>0:
        print(0)
    else:
        print(-1)
        