n,i = list(map(int,input().split()))
lst = list(map(int,input().split()))
i-=1
mp = {}
mp[0] = lst[i]
dis = 1
uniq = []
mx = max(n-i+1,i+1-0)
while dis < mx-1:
    if i + dis < n:
        mp[dis] = mp.get(dis,0) + lst[dis+i]
    else:
        uniq.append(dis)
    if i - dis >= 0:
        mp[dis] = mp.get(dis,0) + lst[i-dis]
    else:
        uniq.append(dis)
    dis+=1
res = mp[0]
del mp[0]
for key, value in mp.items():
    if key in uniq or value == 2:
        res+=value
print(res)
