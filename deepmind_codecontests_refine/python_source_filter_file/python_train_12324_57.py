n=int(input())
num=0
for i in range (n):
    b=str(input())
    if(b=="++X" or b=="X++"):
       num+=1
    elif(b=="--X" or b=="X--"):
       num-=11     
print(num)