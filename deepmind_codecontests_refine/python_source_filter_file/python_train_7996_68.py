S = input()

K = int(input()) - 1

for i in range(K):
  if not S[i] == '1':
    print(S[i])
    exit()
else:
  print(S[i])
