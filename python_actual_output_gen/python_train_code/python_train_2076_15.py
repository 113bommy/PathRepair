n=int(input())
s=[[]for i in range(n+1)]
d=[1]
s[int(input())].append(0)
for i in range(1,n):
    j=int(input())
    t=0
    s[j].append(i)
    if len(s[j])>1:
        if s[j][-2]!=s[j][-1]-1:
            t+=d[i-1]+d[s[j][-2]]
        else:
            t+=d[i-1]
    else: 
        t+=d[i-1]
    d.append(t)
print(d[-1]%(10**9+7))   