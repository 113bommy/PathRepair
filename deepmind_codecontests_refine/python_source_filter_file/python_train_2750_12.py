input()
l=map(int,input().split())
res={0:0}
for i in l:
    if i in res.keys():
        res[i]+=1
    else:
        res[i]=1
print(max(res.values()),len(set(l)))
