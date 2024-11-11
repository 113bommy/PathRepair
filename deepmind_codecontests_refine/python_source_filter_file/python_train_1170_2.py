for i in range(int(input())):
  list = [int(u) for u in input().split()]
  n=list[0]
  m=list[1]
  x=list[2]
  y=list[3]
  sum=0

  for z in range(n):
    l = input()
    w=""
    
    for k in range(len(l)):
      ch=l[k]
      if(ch!='*'):
        w+=ch
      
      if((ch=='.' and k==(len(l)-1)) or ch=="*") :
        a=w[:].count('.')
        
        if(a%2==0):
          if(y>(2*x)):
            sum+=(a*x)
          
          else:
            sum+=(a/2)*y
          w=""
        
        else:
          if(y>(2*x)):
            sum+=(a*x)
          
          else:
            d=x+((a-1)*y)
            sum+=d
          w=""

  print(int(sum))