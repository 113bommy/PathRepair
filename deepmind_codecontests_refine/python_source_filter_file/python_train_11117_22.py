n,m=map(int,input().split())
s=[0]*n
t=[0]*n
for i in range(m):
    a,b=map(str,input().split())
    a,
    a=int(a)-1
    if not s[a]:
        if b=="WA":
            t[a]+=1
        else:
            s[a]=1
print(sum(s),sum(t[i] for i in range(n)if s[a]))