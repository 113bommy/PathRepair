n,a,b=map(int,input().split())
s=input()
all=a+b
inter=b
for i in range(n):
  if all==0:
    print('No')
  elif s[i]=='a':
    print('Yes')
    all-=1
  elif s[i]=='b' and inter>0:
    print('Yes')
    all-=1
    inter-=1
  else:
    print('No')