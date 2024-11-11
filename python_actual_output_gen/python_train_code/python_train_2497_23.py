m=[]
c=0
for i in range(5):          
    a =list(input())
    m.append(a) 
#print(m[1][4])
for i in range(5):
    for j in range(5):
        if(m[i][j]=="1"):
            c=abs(2-i)+abs(2-j)
print(c)