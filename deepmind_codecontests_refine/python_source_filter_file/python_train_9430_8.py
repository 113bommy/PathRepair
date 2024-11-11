k=[]
m=0
for i in range(3):
     s=input()
     s=s.lstrip()
     s=s.rstrip()
     a=s.count("a")
     e=s.count("e")
     i=s.count("i")
     o=s.count("o")
     u=s.count("u")
     if a+e+i+o+u==5 and (i==0 or i==2):
          m+=1
     elif a+e+i+o+u==7 and i==1:
          m+=1
if m==3:
     print("YES")
else:
     print("NO")
               
          
               
                    
          
