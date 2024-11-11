n,m = list(map(int,input().split()))

minI=maxI=minJ=maxJ = -1

sumOfB =0
for x in range(n):
  s = input()
  for el in range(len(s)):
    if s[el] =='B':
      sumOfB +=1
      if minI == -1:
        minI=maxI = el
        minJ =maxJ =x
        continue
      if minI >el:
        minI =el
      if maxI <el:
        maxI = el
      if minJ >x:
        minJ =x
      if maxJ <x:
        maxJ = x
if(max(maxI - minI,maxJ - minJ) > min(n,m)):
  print (-1)
else:
  print(max(maxI - minI + 1,maxJ - minJ + 1)**2-sumOfB)

