h,w,m=map(int,input().split())

r=[0]*h
c=[0]*w
s=set()
for _ in range(m):
    i,j=map(int,input().split())
    i-=1
    j-=1
    r[i]+=1
    c[j]+=1
    s.add(i*w+j)

rmx=max(r)
cmx=max(c)
rc=[i for i in range(h) if r[i]==rmx]
cc=[j for j in range(w) if c[j]==cmx]

ans=rmx+cmx-1
ok=False
for i in rc:
    for j in cc:
        if i*w+j not in s:
            ans+=1
            ok=True
            break
    if ok:
        break

print(ans)
