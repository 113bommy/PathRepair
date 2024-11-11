N = int(input())
L = [tuple(map(int, input().split())) for _ in range(N)]
L.sort(key=lambda x: x[1])
work = 0
for n in range(N):
  work += L[n][0]
  if work > L[n][1]:
    print('No')
    exit()
print('Yes')