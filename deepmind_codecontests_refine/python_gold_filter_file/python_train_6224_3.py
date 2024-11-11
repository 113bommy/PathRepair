S = input()
s = S[::-1]

cnt = [0]*2019
cnt[0] = 1
number = 0
d = 1

for i in s:
  number += int(i)*d
  cnt[number % 2019] += 1
  d *= 10
  d = d % 2019

ans = 0
for i in cnt:
  ans += i*(i-1) // 2

print(ans)