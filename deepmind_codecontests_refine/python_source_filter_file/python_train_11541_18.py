a,b,c=map(int,input().split())
for i in range(b):
  if (i*a)%b==c:
    print('YES')
    break
print('NO')