n = input()
A = list(map(int, input().split()))
cnt = 0
while all(a % 2 == 0 for a in A):
  A = [a / 2 for a in A]
  cnt += 1
print(count)