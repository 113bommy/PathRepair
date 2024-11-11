n = int(input())
ans = list(map(str,input()))
d = {}
for i in ans:
    if i in d:
        d[i]+=1
    else:
        d[i] = 1
count,count1 = 0,0
if 'z' in d and 'r' in d and 'e' in d and 'o' in d:
    count = min(d['z'],d['e'],d['r'],d['o'])
    d['z']-=count
    d['e']-=count
    d['r']-=count
    d['o']-=count
if 'o' in d and 'n' in d and 'e' in d:
    count1 = min(d['o'],d['n'],d['e'])
    d['o']-=count1
    d['n']-=count1
    d['e']-=count1
print('one'*count1+'zero'*count)