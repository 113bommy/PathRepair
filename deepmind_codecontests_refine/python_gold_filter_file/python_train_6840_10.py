n,m=input().split()
a=list(map(int,input().split()))
b=[]
def unique(list1):  
    unique_list = [] 
    for x in range(len(list1)): 
        if list1[x] not in unique_list: 
            unique_list.append(list1[x])
            b.append(x)        
    if(int(m)<=len(unique_list)):
        print("YES")
        for i in range(int(m)):
            print(b[i]+1,end=" ")

    
    else:
        print("NO")
unique(a)


