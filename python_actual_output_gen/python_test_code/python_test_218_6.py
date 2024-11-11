n,m,k=map(int,input().split())
n=n%m
for i in range(1,101):
  if n*i%m==0:
    print('YES')
    quit()
print('NO')