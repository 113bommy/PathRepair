h,w=map(int,input().split())
ans=[[-3]*w for _ in range(h)]
s=[input() for _ in range(h)]
for i in range(h):
    tmp=0
    for j in range(w):
        if s[i][j]=="#": tmp=0
        else: tmp+=1
        ans[i][j]+=tmp
    tmp=0
    for j in range(w-1,-1,-1):
        if s[i][j]=="#": tmp=0
        else: tmp+=1
        ans[i][j]+=tmp

for j in range(w):
    tmp=0
    for i in range(h):
        if s[i][j]=="#": tmp=0
        else: tmp+=1
        ans[i][j]+=tmp
    tmp=0
    for i in range(h-1,-1,-1):
        if s[i][j]=="#": tmp=0
        else: tmp+=1
        ans[i][j]+=tmp

print(max( max(ans[i]) for i in range(h) ))