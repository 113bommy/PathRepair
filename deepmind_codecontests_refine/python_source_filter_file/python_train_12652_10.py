a, ta = map(int, input().split())
b, tb = map(int, input().split())
h, m = map(int, input().split(':'))

cnt = 1139 // b

ans = 0

beg = h * 60 + m - tb
end = h * 60 + ta

for i in range(cnt + 1):
    if beg < b * i + 5 * 60 < end:
        ans += 1

print(ans)
