a=0
t=0
c,x=map(int,input().split())
a=x//5
#print('a=',a)
if x%5==0:
    print(a*c)
#elif a==0:
#    print(int((c/5)*x))    
else:
  lst=list(range((a*5)+1,x+1))
  #print('lst=',lst)    
  for z in lst:
    #  print('z=',z)
      e=5-(z%5)
     # print('e=',e)
      while e<=c :          
          t+=1
          e+=5
#          print('t=',t)
#          print('eeeeeee=',e)
  print((a*c)+t) 