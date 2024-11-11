n=int(input())
l=[int(i) for i in input().split()]
m=int(input())
l1=[int(i) for i in input().split()]
if(n<m):
    for i in range(0,len(l)):
        for j in range(0,len(l1)):
            if(((l[i]+l1[j]) not in l) and ((l[i]+l1[j]) not in l1)):
                print(l[i],l1[j])
                c=1
                break
        if(c==1):
            break
else:
    for i in range(0,len(l1)):
        for j in range(0,len(l)):
            if(((l1[i]+l[j]) not in l) and ((l1[i]+l[j]) not in l1)):
                print(l1[i],l[j])
                c=1
                break
        if(c==1):
            break
    
