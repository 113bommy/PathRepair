N,K = map(int,input().split())
S = set()

for n in range(N):
  input()
  S|=set(input().split())

print(N-len(S))