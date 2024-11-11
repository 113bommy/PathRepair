a=list(map(int,input().split()))
b=list(map(int,input().split()))
tup1=[[0,1,0],[1,1,0],[1,1,1],[0,1,1]]
tup2=[[0,1,0],[1,1,0],[1,0,0],[0,0,0]]
tup3=[[0,0,1],[1,0,1],[1,0,0],[0,0,0]]
tup4=[[0,0,1],[1,1,1],[1,0,1],[0,0,1]]
tup5=[[1,1,1],[1,1,0],[1,0,0],[1,0,1]]
tup6=[[0,1,0],[0,0,0],[0,0,1],[0,1,1]]
if a in tup1 and  b in tup1:
  print('YES')
elif a in tup2 and  b in tup2:
  print('YES')
elif a in tup3 and  b in tup3:
  print('YES')
elif a in tup4 and  b in tup4:
  print('YES')
elif a in tup5 and  b in tup5:
  print('YES')
elif a in tup6 and  b in tup6:
  print('YES')
else:
  print('NO')
    
  
  
  
  
  
  
  