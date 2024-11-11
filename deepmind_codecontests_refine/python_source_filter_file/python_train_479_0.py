n = int(input())
a = input().split()
an = 0
sum = int(a[n - 1])
cnt = {}
for x in range(n):
  cnt[int(a[x])] = 0
  cnt[int(a[x]) + 1] = 0
  cnt[int(a[x]) - 1] = 0

cnt[int(a[n - 1])] = 1
x = n - 2
print(a)
while x >= 0:
  real_sum = sum - (cnt[int(a[x])] * int(a[x]) + cnt[int(a[x]) + 1] * (int(a[x]) + 1) + (cnt[int(a[x]) - 1] * (int(a[x]) - 1)))
  an += real_sum - int(a[x]) * (n - (x + 1) - cnt[int(a[x])] - cnt[int(a[x]) + 1] - cnt[int(a[x]) - 1])
  cnt[int(a[x])] += 1
  sum += int(a[x])
  x -= 1

print(an)
