a,b,c=map(int,input().split())
a*=10**100
a//=b
a=str(a)
while len(a)!=100:
    a='0'+a
c=str(c)
if c in a:
    for i in range(100):
        if a[i]==c:
            print(i+1)
            break
else:
    print(-1)