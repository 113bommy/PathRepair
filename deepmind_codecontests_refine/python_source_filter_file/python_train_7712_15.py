n = int(input())
a = list(map(int, input().split()))
s = []
ss = 0
for i in range(n):
    ss += a[i]
    s.append(ss)

rs = []
ss = 0
for i in range(n - 1, -1, -1):
    ss += a[i]
    rs.append(ss)

#print(s)
#print(rs)
i = 0
j = 0
mx = 0
while i + j < n:
    if s[i] < rs[j]:
        i += 1
    elif s[i] > rs[j]:
        j += 1
    else:
        if s[i] > mx:
            mx = s[i]
        i += 1
        j += 1
if n == 1:
    mx = 0
print(mx)