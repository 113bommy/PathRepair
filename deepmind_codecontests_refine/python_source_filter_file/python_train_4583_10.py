import sys
from collections import deque
def m():
 s=sys.stdin.readlines()
 q=int(s[0].split()[1])
 f=lambda x,y:(x,int(y))
 d=deque(map(*e.split())for e in s[1:])
 t,a=0,[]
 while d:
  k,v=d.popleft()
  if v>q:v-=q;t+=q;d.append([k,v])
  else:t+=v;a+=[f'{k} {t}']
 print('\n'.join(a))
if'__main__'==__name__:m()
