n = int(input())
a = input()
f1, f2 = 0, 0
st = True
cur = 0
ans = ""
while cur < n:
    if cur < n - 2 and a[cur] + a[cur + 1] + a[cur + 2] != "ogo":
        ans += a[cur]
        cur += 1
        continue
    ans += "***"
    cur += 1
    while cur + 1 < n and a[cur] == "g" and a[cur + 1] == "o":
        cur += 2
print(ans)