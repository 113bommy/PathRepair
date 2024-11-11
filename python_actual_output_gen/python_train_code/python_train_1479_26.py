N = int(input())
li = list(map(int, input().split))
li.sort()
P = 0
for i in range(N):
  P += li[i*2]
print(P)