n= int(input())



for i in range(n):
         x,y,a,b = input().split()
         x=int(x)
         y=int(y)
         a=int(a)
         b=int(b)

         if((x+y) % (a+b) == 0):
                  x=int((y-x)/(a+b))
                  if(x==0):
                      print(-1) 
                  else:
                      print(x)
         else:
                  print(-1)