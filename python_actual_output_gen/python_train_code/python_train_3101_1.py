x,y=map(int,input().split())
org=1
copy=0
if x==1 and y==0:
  print('No')
elif org==y and x==copy:
  print('Yes')
else:
  org=org+y-1
  if org==1 and x!=0:
    print('No')
  else:  
    copy=org-1
    if org==y and x==copy:
      print('Yes')
    elif copy>x:
      print('No')
    elif (x-copy)%2==0:
      print('Yes')
    else:
      print('No')
    
  

