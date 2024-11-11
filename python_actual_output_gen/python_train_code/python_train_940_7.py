s=input()
ans=0
cnt=0
for ss in s:
 if ss in 'ATGC':
  cnt+=1
 else:
  ans=max(ans,cnt)
  cnt=0
print(ans)