n=int(input());a=int(input());b=int(input());c=int(input())
r=0;dist=0
for i in range(n-1):
   if r==0:
       if a<b:
          dist+=a
          r=1
       else:
           dist+=b
           r=2
   elif r==1:
       if a<c:
          dist+=a
          r=0
       else:
           dist+=c
           r=2    
   elif r==0:
       if c<b:
          dist+=c
          r=1
       else:
           dist+=b
           r=0       

print(r)    