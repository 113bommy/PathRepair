n, m = (int(i) for i in input().split())
inputMatrix=[[0 for i in range(m)] for j in range(n)]
# for each row
for i in range(n):
  inputMatrix[i]=list(input())
result=''
needToBreak=False
for i in range(n):
  if needToBreak:
      break
  for j in range(m):
    if needToBreak:
      break
    if inputMatrix[i][j]!='*':
      mineCounter=0
      for di in range(-1, 2):
        for dj in range(-1, 2):
          neighborI=i+di
          neighborJ=j+dj
          if 0<=neighborI<n and 0<=neighborJ<m:
            if inputMatrix[neighborI][neighborJ]=='*':
              mineCounter+=1
      if inputMatrix[i][j]=='.' and mineCounter==0:
        result='YES'
      elif inputMatrix[i][j]=='.' and mineCounter!=0:
        result='NO'
        needToBreak=True
      elif int(inputMatrix[i][j])==mineCounter:
        result='YES'
      else:
        result='NO'
        needToBreak=True
print(result)