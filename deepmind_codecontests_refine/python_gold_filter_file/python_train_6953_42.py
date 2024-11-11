a = int(input())
for i in range(1,10,1):
  if a % i == 0 and a/i < 10:
    print('Yes')
    exit(0)
print('No')