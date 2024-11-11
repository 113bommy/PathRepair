A,B,C = map(int,input().split())
for i in range(B):
  if (i+1)*A%B== C:
    print('Yes')
    exit()
print('No')
