n,m=map(int,input().split())
f=list(map(int,input().split()))
b=list(map(int,input().split()))
a=[-1]*100050
for i in range(n):
  if a[f[i]]==-1:a[f[i]]=i
  else :a[f[i]]=-2
for i in b:
  if a[i]==-1:exit(print('Impossible'))
for i in b:
  if a[i]==-2:exit(print('Ambiguity'))
print('Possible')
for i in b:print(a[i]+1,end=' ')