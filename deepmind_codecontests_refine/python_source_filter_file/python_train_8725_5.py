a,b = map(int,input().split())

if b%2 != 0:
  print(pow(a//b,3))
else:
  print(pow(a//b,3)+pow(((a+b//2)//a),3)
