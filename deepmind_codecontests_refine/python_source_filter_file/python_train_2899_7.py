s=input()
ans=1000
for i in range(26):
  if chr(97+i) not in s:continue
  S=s
  cnt=0
  while(len(set(S)))!=1:
    cnt+=1
    t=""
    for j in range(len(S)-1):
      if S[j] == chr(97+i) or S[j+1] == chr(97+i):
        t+=chr(97+i)
      else:
        t+=S[j]
  ans=min(cnt,ans)
print(ans)