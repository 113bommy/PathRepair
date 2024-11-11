N = int(input())

W = [input() for w in range(N)]

for i in range(1,len(W)):
  if (W[i-1][-1] != W[i][0]) or (W[i] in W[:i] == True):
    print("No")
    break
else:print("Yes")