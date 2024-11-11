N,K,C = map(int,input().split())
S = str(input())
works1 = 0
works2 = 0
l1 = []
l2 = []
i = 0
while i < N and works1 < K:
  if S[i] == "o":
    l1.append(i+1)
    i = i+C+1
    works1 += 1
  else:
    i = i+1
i = N-1
while i > -1 and works2 < K:
    if S[i] == "o":
      l2.append(i+1)
      i = i-C-1
      works2 = works2+1
    else:
      i = i-1

for i in range(len(l1)):
  if l1[i] in l2 :
    print(l1[i])