f=lambda a:any(all(b)for b in a)or all(a[i][i]for i in(0,1,2))   
a=eval('list(map(int,input().split())),'*3)
exec('b=int(input());a=[[u*(u!=b)for u in t]for t in a];'*int(input()))
a=[[not u for u in t]for t in a]
print('NYoe s'[f(a)|f(t[::-1]for t in zip(*a))::2])