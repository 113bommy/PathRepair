str_1=input()  
list_a=list(str_1)  
a=len(list_a)  
d='' 
s=0 
list_b=[65,69,73,79,85,97,101,105,111,117]  
for i in range(a):  
 c=list_a[i]  
 for j in range(10):  
  b=list_b[j]  
  if ord(c)==int(b):   
   s=s+1 
 if s==1:
  s=0
 elif ord(c)<97:  
  c=chr(ord(c)+32) 
  d+= '.' 
  d+=c 
 else:  
  d+='.' 
  d+=c  
print(d)