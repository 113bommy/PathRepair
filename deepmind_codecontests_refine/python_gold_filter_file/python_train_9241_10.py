K=int(input())
S=input()

if len(S) > K:
  S = S[:K]
  S += "..."
print(S)