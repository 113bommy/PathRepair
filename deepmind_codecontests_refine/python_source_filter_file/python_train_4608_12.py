for i in range(int(input())):
 a,b,n,m=map(int,input().split())
 if((n+m<=a+b) and (m<min(a,b)) and (n+m)>0):
  print("Yes")
 else:
  print("No")