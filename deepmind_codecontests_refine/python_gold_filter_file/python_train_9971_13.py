import statistics

n = int(input())
la = []
lb = []
for i in range(n):
  a, b = map(int, input().split())
  la.append(a)
  lb.append(b)
a = statistics.median(la)
b = statistics.median(lb)
if n % 2 == 1:
  print(b - a + 1)
else:
  print(int((b - a) * 2 + 1))