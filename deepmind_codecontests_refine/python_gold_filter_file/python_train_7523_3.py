n = int(input())
a = map(int,input().split())
sum = 0
cnt = 0
sumList = {0: 0}
for elem in a:
  sum += elem
  if sum in sumList:
    sum = elem
    sumList = {0: 0}
    sumList[elem] = 0
    cnt += 1
  else:
    sumList[sum] = 0
print(cnt)