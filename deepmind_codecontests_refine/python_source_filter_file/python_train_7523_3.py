n = int(input())
a = map(int,input().split())
sum = 0
cnt = 0
sumList = {}
for elem in a:
  sum += elem
  if sum in sumList:
    sum = elem
    sumList = {}
    sumList[elem] = 0
    cnt += 1
  else:
    sumList[sum] = 0
print(cnt)