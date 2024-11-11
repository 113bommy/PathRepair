N, K, C = map(int,input().split())
S = list(input())

A = list()
B = list()

i = 0
num = 0
while num < K:
  if S[i] == "o":
    A.append(i)
    num += 1
    i += 3
  i += 1
i = len(S)-1
num = 0
while num < K:
  if S[i] == "o":
    B.append(i)
    num+=1
    i -= 3
  i -= 1
B.sort()

for i,j in zip(A,B):
  if i == j:
    print(i+1)