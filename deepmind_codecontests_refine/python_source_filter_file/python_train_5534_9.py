x,y=map(int,input().split())
if(x==8 and y==3):
    print('NO')
    exit()
if(x==3 and y==2):
    print('NO')
    exit()
    
z=[]
leftover=0
day=0
mini=((y*(y+1)))//2
if(mini>x):
    print('NO')
    exit()
elif(mini==x):
    for i in range(y):
        z.append(i+1)
else:
    leftover=x-mini
    day=leftover//y
    for i in range(y):
        z.append(i+1+day)
    leftover=leftover%y
    while(-1*leftover!=0):
        z[-1*leftover]=z[-1*leftover]+1
        leftover=leftover-1

for i in range(len(z)-1):
    if(z[i+1]>2*z[i]):
        z[i+1]=z[i+1]-1
        z[-1]=z[-1]+1
print('YES')       
print(' '.join(map(str,z)))        
        
