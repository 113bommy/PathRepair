k=input().split()
r=int(k[0])
p=int(k[1])
m=int(k[2])
print((((m+1)//2)+(p-1))//p, end=" ") 
print((m+1)//2-((((m+1)//2)+(p-1))//p-1)*p, end=" ") 
if m//2==0:
    print("R")
else:
    print ("L")