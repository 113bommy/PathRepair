s=input()
m=int(1e9)
d=[1 for i in range(len(s))]
f=[0 for i in range(10001)]
f[1]=1
f[2]=2
g=[]
for i in range(3, 10001):
    f[i] = (f[i - 1] + f[i - 2]) % m
for i in range(1,len(s)):
    if s[i] == s[i-1] and (s[i] in 'un'):
        d[i] = d[i-1] + 1
    else:
        g.append(d[i-1])
g.append(d[-1])
g = [gi for gi in g if gi > 1]
if ('m' in s) or ('w' in s):
    print(0)
else:
    ans=1
    for gi in g:
        ans *= gi
        ans %= m
    print(ans)