

def sweep(a):
    temp=0
    for i in range(len(a)):
        s=0
        for j in range(len(a)):
            if a[i] == a[j]:
                s +=1
            
        temp =  max(temp,s)
    

    return temp


###################################################
buffer_size = int(input())
a=[]

for i in range(buffer_size):
    a.append(input())
    
#print(a)
print(sweep(a))