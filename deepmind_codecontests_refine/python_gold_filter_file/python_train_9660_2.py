S = input()
res = [0]*(len(S)+1)

# 左から探索
for i in range(len(S)):
  if S[i]=='<':
    res[i+1]=res[i]+1
    
for i in range(len(S)-1,-1,-1):
  if S[i]=='>':
    res[i]=max(res[i],res[i+1]+1)
    
print(sum(res))