import bisect
s=input()
L=len(s)
s*=2
t=input()
pl={chr(i+97):[] for i in range(26)}
for i in range(len(s)):
  pl[s[i]]+=[i]
cnt=0
rem=0
for i in t:
  if pl[i]==[]:print(-1);exit()
  cnt+=pl[i][bisect.bisect_right(pl[i],rem)]-rem
  rem=cnt%L
print(cnt+1)