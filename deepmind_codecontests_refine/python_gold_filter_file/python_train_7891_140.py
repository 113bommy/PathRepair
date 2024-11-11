S=input()

ans=1000
for i in range(0,len(S)-2):
  ans=min(ans,abs(753-int(S[i:i+3])))
print(ans)