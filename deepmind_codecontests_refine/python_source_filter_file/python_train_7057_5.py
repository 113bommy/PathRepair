s = input()
S = list(s)
K = int(input())
cnt1 = 0
cnt2 = 0
if len(set(S)) == 1:
  print(len(S) // 2 * K)
  exit()
for i in range(len(S)-1):
  if S[i] == S[i+1]:
    S[i+1] = "#"
    cnt1 += 1
SS = list(s + s)
for i in range(len(S)*2-1):
  if SS[i] == SS[i+1]:
    SS[i+1] = "#"
    cnt2 += 1
print(cnt1 + (cnt2 - cnt1) * (K - 1))