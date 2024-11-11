from collections import Counter
n,m = map(int,input().split())
f = ''
s = ''
for _ in range(n):
    a = input()
    b = Counter(a)
    c = ''
    for i in range(m):
        if b.get(a[i])>1:
            c+='1'
        else:
            c+='0'
    f+= c
    s+= a
for i in range(m):
    d = s[i::m]
    e = Counter(d)
    for j in range(n):
        if e.get(d[j])>1:
            f=f[:i+j*m]+'1'+f[i+j*m+1:]
s1 = ''
for i in range(n*m):
    if f[i]=='0':
        s1+=s[i]
print(s1)
