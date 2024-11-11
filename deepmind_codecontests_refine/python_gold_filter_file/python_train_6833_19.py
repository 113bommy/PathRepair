#for  i in range(int(input())):
#arr=list(map(int,input().split()))
#ls=sorted(arr)
n,k=map(int,input().split())
if k ==1:
  print(n)
else:
  var=bin(n)[2:]
  print(2**(len(var))-1)

