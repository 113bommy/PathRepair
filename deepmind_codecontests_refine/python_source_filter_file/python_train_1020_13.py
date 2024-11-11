X=int(input())
def momo(s)
if int(s)>X:
  return 0
 
nagi=1 if all(s.count(c)>0 for c in '753') else 0
  for c in '753':
    nagi+=momo(s+c)
    return nagi
print(momo('0'))