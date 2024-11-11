s = input()
t = input()
n = len(s)
m = len(t)
l = [-1]
r = [n]
c = 0
for i in range(n):
    if s[i] == t[c]:
        l.append(i)
        c += 1
        if c >= m:
            break
c = 0
for i in range(n):
    if s[-1-i] == t[c]:
        r.append(n-1-i)
        c += 1
        if c >= m:
            break
mx = 0
for i in range(m+1):
    mx = max(mx, r[m-i]-l[i]-1)
print(mx)
