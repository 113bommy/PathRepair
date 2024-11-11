n, k = map(int, input().split())
l = list(map(int, input().split()))
l.sort(reverse=True)
# print(l)
a = 0
maisu = 0
end_maisu = 0
ans = 0
for i in range(n):
    maisu += 1
    a += l[i]
    if a >= k:
        a -= l[i]
        ans += 1
        end_maisu = maisu
        maisu = 0
end_maisu -= 1
if end_maisu < 0:
    end_maisu = 0
# print(end_maisu - 1)
print(n - ans - end_maisu)
