n=int(input())
b=[int(t) for t in input().strip().split()]

a=b+[b[-1]]

current=1
is_alternating=False
break_points=[]
for current in range(1,len(a)):
    if(a[current]!=a[current-1] and is_alternating==False):
        break_points.append(current-1)
        is_alternating=True
    elif(a[current]==a[current-1] and is_alternating==True):
        break_points.append(current-1)
        is_alternating=False
        
k=-1
k=-1
for i in range(len(break_points)//2):
    p=break_points[2*i]
    q=break_points[2*i+1]
    
    if(a[p]==a[q]):
        k=max([k,(q-p+1-1)//2])
        for j in range(p,q):
            a[j]=a[p]
    elif(a[p]!=a[q]):
        k=max([k,(q-p+1-2)//2])
        for j in range(p,(p+q+1)//2):
            a[j]=a[p]
        for j in range((p+q+1)//2,q):
            a[j]=a[q]
print(k)
print(' '.join([str(t) for t in a[:-1]]))
