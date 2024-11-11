s = input()
string = s
n = len(s)

a = []
i = 0
while i < n:
    j = 1
    while i < n-1 and s[i] == s[i+1]:
        i += 1
        j += 1
    a.append(j)
    i += 1
 
s = 0
b = []
n = len(a)
if string[0] == 'o':
    a = [0]+a
    n += 1
for i in range(n):
    if i%2 == 0:
        a[i] -= 1
for i in range(n-1,-1,-1):
    if i%2 == 0:
        s += a[i]
    b.append(s)
b.reverse()
b = list(b)
#print(b)
 
s = 0
ans = 0
for i in range(n):
    if i%2:
        ans += s*b[i]*a[i]
    else:
        s += a[i]
print(ans)