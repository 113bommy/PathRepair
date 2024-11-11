n=int(input())
d=''.join([''.join(input().split())for i in range(n//19+1)])
i=0
while True:
 if d.find(str(i))==-1:
  print(i)
  exit() 
 i+=1