def main():
  n=int(input())
  corner=[]
  middle=[]
  centre=[]
  arr=input().split()
  cat=[]
  for x in range(n*n):
    hold=int(arr[x])
    bo=False
    for y in range(len(cat)):
      if hold==cat[y][0]:
        cat[y][1]+=1
        bo=True
        break
    if not bo:
      cat.append([hold,1])

  #Determine if possible
  if n%2==1:
    for x in range(len(cat)):
      if cat[x][1]%2==1:
        centre.append(cat[x][0])
        cat[x][1]-=1
    if len(centre)!=1:
      print("NO")
      return 0
    for x in range(len(cat)):
      if cat[x][1]%4==2:
        middle.append(cat[x][0])
        cat[x][1]-=2
    if len(middle)>(n-2):
      print("NO")
      return 0
  else:
    for x in range(len(cat)):
      if cat[x][1]%4!=0:
        print("NO")
        return 0
  print("YES")

  #sieve out the remaining values
  x=0
  while len(corner)<(n//2)*(n//2) and x<len(cat):
    if cat[x][1]>0:
      cat[x][1]-=4
      corner.append(cat[x][0])
    else:
      x+=1
  while x<len(cat):
    if cat[x][1]>0:
      cat[x][1]-=2
      middle.append(cat[x][0])
    else:
      x+=1

  #forming matrix
  arr=[[0 for x in range(n)] for y in range(n)]
  if n%2==1:
    arr[n//2][n//2]=centre[0]
    #print(middle)
    #print(len(corner))
    for x in range(n//2):
      arr[n//2][x]=middle[x]
      arr[n//2][n-1-x]=middle[x]
      arr[x][n//2]=middle[n-2-x]
      arr[n-1-x][n//2]=middle[n-2-x]
  x=0
  for y in range(n//2):
    for z in range(n//2):
      arr[y][z]=corner[x]
      arr[y][n-1-z]=corner[x]
      arr[n-1-y][z]=corner[x]
      arr[n-1-y][n-1-z]=corner[x]
      x+=1
  
  for x in range(n):
    for y in range(n-1):
      print(arr[x][y],end=" ")
    print(arr[x][n-1])
main()
