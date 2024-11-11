s=input().split()
s1=int(s[0])
if s[2]=='week':
   if s1==5 or s1==6 or s1==7:
   	  print(53)
   else:
   	   print(52)
else:
    if s1==31:
         print(7)
    elif s1==30:
          print(11)
    else:
      print(12)