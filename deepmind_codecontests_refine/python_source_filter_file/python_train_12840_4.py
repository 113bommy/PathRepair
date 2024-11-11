s = input().split()
n = int(s[0])
s1 = input().split()
a = []
num = 0
while num < n :
    a.append(int(s1[num]))
    num += 1
num = 1
while num < n :
    a[num] += a[num - 1]
    num += 1
num = 1
ans = 0
while num < n - 1 :
    if a[n - 1] - a[num] == a[num] : ans += 1
    num += 1
print(ans)