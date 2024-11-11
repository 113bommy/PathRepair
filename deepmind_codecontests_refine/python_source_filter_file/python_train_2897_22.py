import sys
#input = sys.stdin.readline

def chr2ord(c):
  return ord(c) - ord('a')

N = int(input())
S = []
for i in range(N):
  wk = list(input())
  S.append(wk)

ANS = 0
# A=0として、0<=B<Nをためす。
# こたえはN倍。
for b in range(N):
  cnt = 0
  B = [['X' for _ in range(N)] for _ in range(N)]
  for i in range(N):
    for j in range(N):
      B[i][j] = S[i][(j+b)%N]
  #print(B)
  for i in range(N):
    for j in range(N):
      if B[i][j] == B[j][i]:
        cnt += 1
  
  if cnt == N*N:
    ANS += N
print(ANS)