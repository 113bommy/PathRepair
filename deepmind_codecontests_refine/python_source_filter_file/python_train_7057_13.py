S = list(input())
K = int(input())
cnt = 1
ans = 0
counter = []

if len(S) == 1:
  print(len(S)*K//2)
  exit()
  
else:
  for i in range(len(S)-1):
    if S[i] == S[i+1]:
      cnt += 1
    else:
      counter.append(cnt)
      cnt = 1
  counter.append(cnt)
    
  for l in counter:
    ans += (l//2)*K

  if S[0] == S[-1]:
    a = counter[0]
    b = counter[-1]
    ans -= (a//2 + b//2 - (a+b)//2)*(K-1)
  
  print(ans)