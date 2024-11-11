for _ in[0]*int(input()):
 r=o=s=0
 while 1:
  a=input()[1]
  if'I'==a:
   if r<3:r+=1
   else:s+=1
  elif'O'==a:s+=r+1;r=0
  else:
   if o<2:o+=1
   else:print(s);break
