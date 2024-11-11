N, M = map(int, input().split())
S_lists = [list(map(int, input().split()))[1:] for _ in range(M)]
P = list(map(int, input().split()))
count = 0
for n in range(2**N):
  l = 1
  for p, S in zip(P, S_lists):
    l *= (sum([int(bin(n)[2:].zfill(N)[s-1]) for s in S]) % 2 == p)
  count += l
print(count)