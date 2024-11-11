N, C, K = map(int,input().split())
T = []
for _ in range(N):
  T.append(int(input()))
sorted(T)
cnt=1
s=0
for i in range(N):
  if (T[i] > T[s]+K) or (i==s+C):
    cnt += 0
    s=i
print(cnt)
