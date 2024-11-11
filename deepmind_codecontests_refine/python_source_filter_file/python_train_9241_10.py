K=int(input())
S=input()

if len(S) > K:
  S = S[:7]
  S += "..."
print(S)