for _ in range(int(input())):
  N, K = map(int,input().split())
  A = list(map(int,input().split()))
  A.sort()
  
  a = A[0]
  if len(A) == 1:
    print(max(0, a - K))
    continue
    
  S = [a]
  for v in A[1:]:
    S.append(S[-1] + v)
  #print(S)
  ans = 1 << 60
  for l in range(N-1):
    x = max(0, -((-(S[-l-1] + l * a - K)) // (l + 1)))
    #print(a, x, l)
    ans = min(ans, x + l)
    
  print(ans)
    