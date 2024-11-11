N = int(input())
for i in range(1,9):
  if N % i == 0 and N/i <= 9:
    print('Yes')
    exit(0)
print('No')