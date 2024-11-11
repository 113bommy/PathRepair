from collections import defaultdict
n=int(input())
l=list(map(int,input().strip().split(' ')))
d=defaultdict(lambda:0)
index=-1;maximum=-1
for i in range(n):
    d[l[i]]+=1
    if(d[l[i]]>d[maximum]):
        index=i
        maximum=l[i]
new_list=[]
op_count=n-(d[l[index]])
for j in range(index-1,-1,-1):
    if l[j]<maximum:
        new_list.append((1,j,j+1))
    elif l[j]>maximum:
        new_list.append((2,j,j+1))
for j in range(index+1,n,1):
    if l[j]<maximum:
        new_list.append((1,j,j-1))
    elif l[j]>maximum:
        new_list.append((2,j,j-1))
print(op_count)
for i in new_list:
    print(i[0],i[1]+1,i[2]+1,sep=' ')
    
    
