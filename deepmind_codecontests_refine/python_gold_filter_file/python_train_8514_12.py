import sys
input = sys.stdin.readline
import bisect
S = input()
E = {S[i]:[] for i in range(len(S)-1)}
for i in range(len(S)-1):
  E[S[i]].append(i)
T = input()
a = len(S)-1
ans=0
now = -1
for i in range(len(T)-1):
  if not T[i] in E.keys():
    print(-1)
    exit()
  s=E[T[i]]
  b= bisect.bisect_right(s,now)
  #print(s,b,now)
  if b==len(s):
    ans+=s[0]+1+a-1-now
    now=s[0]
  else:
    ans+=s[b]-now
    now=s[b]
print(ans)
