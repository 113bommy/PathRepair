n,m = map(int,input().split())
s = input()
sl =['.']+[i for i in s]
for _ in range(m):
    l,r,c1,c2 = input().split(' ')
    l = int(l)
    r = int(r)
    for i in range(l,r+1):
        if(sl[i]==c1):
            sl[i] = c2
ans = ''
for i in sl:
    ans+=i
print(ans)