N = int(input())
S = input()
T = input()

for i in range(N, 0, -1):
  if(S[-i:] == T[:i]):
    tmp = i
    break
print(N*2-tmp)