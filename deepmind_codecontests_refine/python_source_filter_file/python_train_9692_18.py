n, m = map(int, input().split())
s = []
for i in range(n):
    s.append(list(input()))

l = 0
r = 0
for i in range(n):
    for j in range(m):
        if s[i][j] == 'B':
            l = i
            r = j
            break
    else:
        continue
    break
leng = 0
while r < n and s[l][r] == 'B':
    leng += 1
    r += 1
print(l+1+leng//2, r-leng//2)