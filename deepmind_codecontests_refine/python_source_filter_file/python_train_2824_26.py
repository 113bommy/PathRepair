str_0=input()
list_0=str_0.split()
n=int(list_0[0])
k=int(list_0[1])
str_1=input()
list_1=str_1.split()
n_1=1
list_2=[]
if n >1:
    if n>2:
        for i in range(n-1):
            if list_1[i]==list_1[i+1]:
                list_2.append(n_1)
                n_1=1
            else:
                n_1+=1
        list_2.append(n)
    else:
        if list_1[0]==list_1[1]:
            list_2.append(1)
        else:
            list_2.append(2)
else:
    list_2.append(1)
list_2.sort()
if len(list_2)==1:
    print(list_2[0])
else:
    print(list_2[-1])
    
        
    

