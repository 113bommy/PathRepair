N,K = list(map(int,input().split()))
S = list(map(int,input().split()))
result = [(sum(S[:K])+K)/2]
for i in range(N-K-1):
  result.append(result[-1]+S[i+K]/2-S[i]/2)
print(max(result))