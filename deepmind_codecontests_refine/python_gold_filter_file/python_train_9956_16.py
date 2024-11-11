a,b,c=map(int,input().split())
a*=10**100000
a//=b
a=str(a)
while len(a)!=100000:
    a='0'+a
c=str(c)
if c in a:
    for i in range(100000):
        if a[i]==c:
            print(i+1)
            break
else:
    print(-1)