from collections import Counter
N = int(input())
S = [str(sorted(input())) for _ in range(N)]
count = 0
for i in Counter(S).values():
  count = 1*(i-1)//2
print(count)