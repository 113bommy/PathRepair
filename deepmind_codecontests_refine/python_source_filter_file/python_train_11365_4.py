n = int(input())
m = input()
ans = 10 ** 55000
ind = n // 2
while(ind >= 0):
    if (m[ind] != '0'):
        break
    ind -= 1
if (ind > 0):
    ans = min(ans, int(m[:ind]) + int(m[ind:]))
ind = n // 2 + 1
while(ind < n):
    if (m[ind] != '0'):
        break
    ind += 1
if (ind < n):
    ans = min(ans, int(m[:ind]) + int(m[ind:]))
print(ans)
