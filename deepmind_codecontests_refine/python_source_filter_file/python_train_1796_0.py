cases = int(input())
for x in range(cases):
  (n, k) = tuple(map(int, input().split()))
  #print(n, k)
  if (n-(k-1))%2==1 and (n-(k-1)) >= 0:
    print('YES')
    print("1 "*(k-1) + str(n-(k-1)))
  elif (n-(k-1)*2)%2==0 and (n-(k-1)*2) >= 0:
    print('YES')
    print("2 "*(k-1) +str(n-(k-1)*2))
  else:
    print('NO')