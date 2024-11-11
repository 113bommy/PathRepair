n = int(input())
f = []
ans = ''

for i in range(1001):
    if len(f) < 2:
        f.append(1)
    else:
        f.append(f[-1]+f[-2]) 

for j in range(1, n+1):
    if j in f:
        ans += 'O'
    else:
        ans += 'o'

print(ans)