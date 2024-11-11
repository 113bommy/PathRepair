def convert(s): 
  
    # initialization of string to "" 
    new = "" 
  
    # traverse in the string  
    for x in s: 
        new += x  
  
    # return string  
    return new 
t=int(input())
for i in range(t):
  m=[]
  a,b,c=map(int,input().split())
  if b>0:
    for i in range(a+1):
      m.append('0')
    for i in range(c+1):
      m.append('1')
    for i in range(b-1):
      if i%2==0:
        m.append('0')
      else:
        m.append('1')
  else:
    if a>0:
      for i in range(a+1):
        m.append('0')
    else:
      for i in range(b+1):
        m.append('1')
  print(convert(m))