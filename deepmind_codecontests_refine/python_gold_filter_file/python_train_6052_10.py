#Ashish_Sagar
l=list(input())
flag1=0
flag2=0
for i in range(len(l)):
    
    if l[i]=='0':
        if flag1==0:
            print(1,4)
            flag1=1
        else:
            print(3,4)
            flag1=0
    else:
        print(flag2%4+1,1)
        flag2+=1
            
