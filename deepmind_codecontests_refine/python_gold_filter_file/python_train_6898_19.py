for _ in range(int(input())):
   s=list(input())
   a=[]
   c=0
   x=0
   if(all(x=='0' for x in s)):
       print('0')
   elif(all(x=='1' for x in s)):
       print(len(s))
   else:
      for i in range(len(s)):
           if(s[i]=='1'):
               c=c+1
           else:
               if(c!=0):
                  a.append(c)
                  c=0
      if(s[-1]=='1'):
           a.append(c)    
      a.sort(reverse=True)
      for i in range(len(a)):
          if(i%2==0):
              x=x+a[i]
      print(x)        
        
           