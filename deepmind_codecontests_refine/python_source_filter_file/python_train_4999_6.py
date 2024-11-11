import collections,sys
def s():
 d=collections.deque()
 input()
 for e in sys.stdin:
  if'i'==e[0]:d.appendleft(e[7:-1])
  else:
   if' '==e[6]:
    m=e[7:-1]
    if m in d:d.remove(m)
   elif'i'==e[7]:d.pop()
   else:d.popleft()
 print(*d)
if'__main__'==__name__:s()
