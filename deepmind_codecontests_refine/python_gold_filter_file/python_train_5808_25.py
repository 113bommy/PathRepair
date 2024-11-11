import sys
K = list(map(int,input().split()))
N = K[0]
S = sum(K[1:4])

if S == 0:
  print("No")
  sys.exit()

s = input()
out = [0 for _ in range(N)]

for ct in range(N):
  #print(K)
  if ct < N-1:
    s_next = input()
    
  if s == "AB":
    i = 1
    j = 2
  elif s == "BC":
    i = 2
    j = 3
  else:
    i = 1
    j = 3
  
  if K[i] + K[j] == 0:
      print("No")
      sys.exit()
  elif K[i] > K[j]:
    K[i] -= 1
    K[j] += 1
    log = j
  elif K[i] < K[j]:
    K[i] += 1
    K[j] -= 1
    log = i
  elif K[i] == K[j]:
    if ct == N-1:
      K[i] += 1
      K[j] -= 1
      log = i
      out[ct] = i
      break
      
    if s_next == "AB":
      i_n = 1
      j_n = 2
    elif s_next == "BC":
      i_n = 2
      j_n = 3
    else:
      i_n = 1
      j_n = 3
      
    if i_n == i or j_n == i:
      K[i] += 1
      K[j] -= 1
      log = i
    else:
      K[j] += 1
      K[i] -= 1  
      log = j
  #print(log)
  out[ct] = log
  if ct < N-1:
    s = s_next

print("Yes")
for o in out:
  print(chr(64+o))