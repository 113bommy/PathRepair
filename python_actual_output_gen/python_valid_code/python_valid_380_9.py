N = int(input())
A,B = map(int,input().split())

lis = []

P = list(map(int,input().split()))

for i in P:
  if i <= A:
    lis[0] += 1
  elif i <= B:
    lis[1] += 1
  else:
    lis[2] += 1
    
print (min(lis))