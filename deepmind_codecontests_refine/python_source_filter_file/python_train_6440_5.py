n,a,b=map(int,input().split())
s=input()
all=a+b
in=b
for i in range(n):
  if all==0:
    print('No')
  elif s[i]=='a':
    print('Yes')
    all-=1
  elif s[i]=='b' and in>0:
    print('Yes')
    all-=1
    in-=1
  else:
    print('No')