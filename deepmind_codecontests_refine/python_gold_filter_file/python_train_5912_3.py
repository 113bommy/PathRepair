N,K,C = (int(i) for i in input().split())
S = str(input())

L = [-1] * K
R = [-1] * K
S_index = 0
count = 0
while count < K:
  if S[S_index] == "o":
    L[count] = S_index
    count += 1
    S_index += C+1
  else:
    S_index += 1

S_index = N-1
count = 0
while count < K:
  if S[S_index] == "o":
    R[count] = S_index
    count += 1
    S_index -= C+1
  else:
    S_index -= 1

R.reverse()
for l,r in zip(L,R):
  if l == r:
    print(l+1)
