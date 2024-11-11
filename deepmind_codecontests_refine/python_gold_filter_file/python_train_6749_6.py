N = int(input())
AB = sorted([list(map(int,input().split())) for _ in range(N)], key = lambda x: -x[1])
CD = sorted([list(map(int,input().split())) for _ in range(N)])

cnt = 0
for c, d in CD:
  for a, b in AB:
    if(a < c and b < d):
      cnt += 1
      AB.remove([a, b])
      break
print(cnt)