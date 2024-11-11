a,b = input().split()
x,y = map(int,input().split())
k = int(input())

if a == k:
  print(x-1,y)
else:
  print(x,y-1)
