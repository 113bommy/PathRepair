import sys

nums=ans=0
for s in sys.stdin:
   jj=s[0]
   if jj=='+':
      nums+=1
   elif jj=='-':
      nums-=1
   else:
      n,t=s.split(':')
      ans+=len(t)*nums
print(ans)