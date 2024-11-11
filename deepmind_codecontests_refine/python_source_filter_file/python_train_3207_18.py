s = input()
a = [0]*len(s)
r, l = 0, 0

for i in range(len(s)):
    r += 1
    if s[i] == 'L':
        a[i-1] += r//2
        a[i] += (r+1)//2
        r = 0
print(a)
for j in range(len(s)-1, -1, -1):
    l += 1
    if s[j] == 'R':
        a[j+1] += l//2
        a[j] += (l+1)//2
        l = 0
    a[j] -= 1

print(*a)

