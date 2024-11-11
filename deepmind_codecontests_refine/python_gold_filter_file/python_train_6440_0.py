(n,an,bn) = list(map(int,input().split()))
s = list(input())
count = 1
foreign = 1
for i in s:

  if i=='a' and an+bn >= count:
    print('Yes')
    count += 1
  elif i=='b' and an+bn >= count and bn >= foreign:
    print('Yes')
    count += 1
    foreign += 1
  else:
    print('No')