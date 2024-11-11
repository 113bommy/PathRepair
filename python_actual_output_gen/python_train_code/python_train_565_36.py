for i in range(int(input())):
   x,y,n=map(int,input().split())
   if x>n:
       print(0)
   elif n%x==y:
       print(n)
   else:
       if n%x>y:
           print(n-(n%x-y))
       elif n%x<y:
           print(n-(x-y+n%x))