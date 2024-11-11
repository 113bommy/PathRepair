import collections
N = int(input())
A = list(map(int, input().split()))
S = [0]
for i in range(len(A)):
  S.append(A[i]+S[i])
L = list(collections.Counter(S).values())
s = 0
for l in L:
  s += int((l-1)*l//2)
print(s)