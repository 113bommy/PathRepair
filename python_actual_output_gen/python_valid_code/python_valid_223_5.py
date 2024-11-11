n=int(input())

for i in range(n):
  if (n-4*i)%7==0 or (n-4*i)%4==0:
    print('Yes')
    exit()
print('No')