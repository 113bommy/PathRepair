s=list(input())
N=len(s)
a=int((N-1)/2)
b=int((N+1)/2)
if  s[::-1]==s and s[:a]==s[b:]:
  print('Yes')
else:
  print('No')