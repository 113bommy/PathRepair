N = int(input())

ans = 0
num_A = 0
num_B = 0
num_BA = 0
for _ in range(N):
  s = input()
  ans += s.count('AB')
  num_A += s.endswith('A')
  num_B += s.startswith('B')
  num_BA += s.startswith('B') * s.endswith('A')

con = min(num_A, num_B)
con -= (num_A == num_B == num_BA)
ans += con
print(ans)