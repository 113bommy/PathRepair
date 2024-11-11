## 681 A
n = int(input())
good = False
for _ in range(n):
    name, before_s, after_s = input().split(' ')
    before = int(before_s)
    after = int(after_s)
    if (before >= 2400 and after < before):
        good = True
if good:
    print("YES")
else:
    print("NO")