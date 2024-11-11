N, K = map(int,input().split())
L = input()
count=0
for i in range(N-1):
  if L[i]==L[i+1]:
    count += 1

print(min(count+2*L, N-1))