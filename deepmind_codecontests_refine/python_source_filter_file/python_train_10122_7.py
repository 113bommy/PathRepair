n = int(input())
while(n>0):
  a,b = map(int, input().split())
  if a==b:
    g=0
    print(g)
  if(a<b):
    s = b-a
    if(s%2 == 1):
      print('2')
    else:
      print('1')
  if(a>b):
    
    s=a-b
    if(s%2 == 0):
      print('1')
    else:
      print('2')
  n=n-1