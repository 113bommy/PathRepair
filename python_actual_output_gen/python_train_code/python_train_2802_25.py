n,k=map(int,input().split())
a=[]
a=0
for i in range(n):
  if a==1:
     print("\n",end="")
     for j in range(n):
      if i==j:
          print(k,end=" ")
      else:
          print("o",end=" ")
          a=1
  else:
      for j in range(n):
          if i == j:
              print(k, end=" ")
          else:
              print("o", end=" ")
              a = 1