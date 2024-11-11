import sys
x=int(input())
a=0
while True:
  for i in range(-64,a):
    if a**5-i**5==x:
      print(a,i)
      sys.exit()
  a+=1
