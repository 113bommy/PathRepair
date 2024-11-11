a=((int,input().split())) #number of games
x=0
y=0
#for i in range(a):
b=list(map(str,input().strip()))    #enter the winning case A or D
for i in range(len(b)):
    if(b[i]=='A'):
        x=x+1
    elif(b[i]=='D'):
        y=y+1
if(x>y):
    print('Anton')
elif(x<y):
    print('Danik')
else:
    print('Friendship')