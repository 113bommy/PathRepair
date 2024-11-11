N, K = map(int,input().split())
AB = sorted([[list(map(int,input().split())) for _ in range(N)]])
cnt = 0
for a, b in AB:
  if(cnt < K - b)
    cnt += b
  else:
    print(a)
    break
