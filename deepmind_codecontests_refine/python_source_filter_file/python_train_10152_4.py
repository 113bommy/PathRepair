l,r,k = map(int,input().split())
res = []
for i in range(10000):
    if k**i>=l and k**i<=r:res.append(k**i)
    else:break
if res==[]:print(-1); quit()
print(' '.join(map(str,res)))