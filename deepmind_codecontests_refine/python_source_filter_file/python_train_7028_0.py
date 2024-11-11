n=int(input())
p=input().rstrip().split(' ')
zero=0;
one = 0;C=-1
for i in range(0,len(p)):
    if int(p[i])==0:
        zero+=1;
    else:
        C=i;
        break;
if(C!=-1):
    back_zero = zero;
    zero = 0;
    l=[]
   # print(C)
    for i in range(C+1,len(p)):
       # print(p[i],i)
        if int(p[i])==0:
            zero+=1;
        else:
            l.append(zero+1)
            zero=0;
    end_zero = zero;
    H=1;
    #print(l)
    if(1):
        for i in range(0,len(l)):
            H=H*l[i]
        print(H)
else:
    print(1)
    
    
    '''
    
    15
1 0 0 1 0 0 0 1 0 0 1 0 0 0 1

'''