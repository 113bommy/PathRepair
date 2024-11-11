def cm(c1,c2,c):
  x1,y1,x2,y2=-1,-1,-1,-1
  if c1%c==0:
    y1=c1//c;x1=c
  else:
    y1=c1//c+1;x1=c1%c

  if c2%c==0:
    y2=c2//c;x2=c
  else:
    y2=c2//c+1;x2=c2%c
  #print(x1,y1,x2,y2)
  if y1==y2:
    if abs(x1-x2)==1:
      return True
    else:
      return False
  else:
    return False
  
n=int(input())
arr=list(map(int,input().strip().split(' ')))
ctr=0;r=-1;c=-1;
while ctr<len(arr)-1:
  c1=arr[ctr]
  c2=arr[ctr+1]
  if abs(c2-c1)!=1:
    c=abs(c2-c1)
    break
  ctr+=1
if c==-1:
  print('YES')
  print(1,max(arr))
else:
  ctr=0;flag=True
  if c==0:
    print('NO')
  else:
    while ctr<len(arr)-1:
      c1=arr[ctr]
      c2=arr[ctr+1]
      if (abs(c2-c1)!=1 and abs(c2-c1)!=c)or(abs(c1-c2)==0):
        print('NO')
        flag=False
        break
      if abs(c2-c1)==1:
        #print(c1,c2,c)
        if cm(c1,c2,c)==False:
          #print(c1,c2)
          print('NO')
          flag=False
          break
    
      ctr+=1
    if flag:
      print('YES')
      print(10**9,c)
    
    

  
  
