def kadane(lis):
    su=0
    n=len(lis)
    max=0
    for i in range(n):
        if lis[i]==0:
            e=-1
        else:
            e=1
        #su+=e
        if e<0:
            su=0
        else:
            su+=1
        if su>max:
            max=su
    return max
def find(lis):
    lis=lis+lis
    #print(lis)
    maximum=kadane(lis)
    maximum1=0
    '''for i in range(n):
        maximum1+=lis[i]
        if lis[i]==0:
            lis[i]=1
        else:
            lis[i]=0
    #print(maximum1)
    maximum1-=kadane(lis)
    print(maximum1)'''
    print(maximum)
   
    #print(max(maximum1,maximum))


n=int(input())
lis=[int(i)for i in input().split()]
find(lis)