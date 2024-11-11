N = int(input())
for i in range(1,10):
  if N % i == 0 and N/i <= 9:
    print('Yes')
    exit(0)
print('No')