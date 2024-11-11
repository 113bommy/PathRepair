N = int(input())
A = list(map(int, input().split()))
B = [0]*(N+1)
ans = []
 
for n in range(N):
  i = N-n
  BB = B[::i]
  if (sum(BB))%2 != A[i-1]:
    B[i] = 1
    ans.append(str(i))
  
print(len(x))
print(' '.join(ans))