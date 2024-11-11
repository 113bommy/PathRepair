s = input().split()

m = int(s[0])
d = int(s[1])

a = [31, 30, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
r = a[m - 1] + (d - 1)

ans = r // 7
if r % 7:
    ans += 1
print(str(ans))
