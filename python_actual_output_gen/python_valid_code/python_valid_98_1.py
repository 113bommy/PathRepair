n, w = map(int, input().split())
a = list(map(int, input().split()))
t1 = [0]
for i in range(1, n):
  t1.append(a[i] - a[i - 1])
 
a = list(map(int, input().split()))
t2 = []
for i in range(1, w):
  t2.append(a[i] - a[i - 1])
 
s = t2 + ['#'] + t1
n = len(s)
pre = [0]
for i in range(1,n):
    j = pre[i-1]
    while j > 0 and s[j] != s[i]:
        j = pre[j-1]
    if s[j] == s[i]:
        j += 1
    pre.append(j)
ans = 0
for i in range(len(t2) + 1, len(pre)):
    if pre[i] == len(t2):
        ans += 1
print(ans)