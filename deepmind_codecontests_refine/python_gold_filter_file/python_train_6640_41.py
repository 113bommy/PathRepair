N = int(input())
A = map(int,input().split())
for a in A:
  if a % 2 == 0 and a % 3 != 0 and a % 5 != 0:
    print('DENIED')
    exit()
print('APPROVED')
