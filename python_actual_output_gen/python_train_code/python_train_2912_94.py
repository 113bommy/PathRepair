x=int(input())
a=x+1
for i in range(a,9000,1):
     d1=int(i/10)
     d2=int(d1/10)
     d3=int(d2/10)
     r1=i%10
     r2=d1%10
     r3=d2%10
     r4=d3%10

     if r1==r2 or r1==r3 or r1==r4 or r2==r3 or r3==r4 or r2==r4 :
         pass
     else:
      
      print(i)
      break
