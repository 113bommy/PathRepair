n=int(input())
a=sorted(list(map(int,input().split())))
a1=[]
a2=[]
a3=[]
i=0
count=0
while(i<len(a)):
    if a[i]<0:
        a1.append(a[i])
        count+=1
        i+=1
    elif a[i]==0:
        a3.append(a[i])
        i+=1
    else:
        a2.append(a[i])
        i+=1
if len(a2)==0:
    a2.append(a1.pop())
    a2.append(a1.pop())
if count%2==0:
    a3.append((a1.pop()))
    
print(len(a1),*a1)
print(len(a2),*a2)
print(len(a3),*a3)
       
    

    
