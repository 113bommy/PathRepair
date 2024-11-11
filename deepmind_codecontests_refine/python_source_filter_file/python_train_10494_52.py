n,a,b,c,d = map(int,input().split())
s = input()

ans = 'Yes'
if '##' in s[a-1:c]:
  ans = 'No'  
if '##' in s[b-1:d]:
  ans = 'No'
  
if c > d:
  if '...' not in s[b-2:d]:
    ans = 'No'

print(ans)    