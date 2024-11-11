for _ in[0]*int(input()):
 s=input();i=0;r=[]
 while i<len(s):
  if'one'== s[i:i+3]:r+=i+1,
  if'twone'==s[i:i+5]:r+=i+3,;i+=4
  if'two'==s[i:i+3]:r+=i+1,
  i+=1
 print(len(r),*r)