n=int(input())
llist=list(map(int,input().split()))
#llist.sort()
mini=1000
for i in range(len(llist)-1):
    
    temp=llist[i]-llist[i+1]
    if(temp<0):
        temp=-temp
    if(mini>temp):
        mini=temp
        ax=i+1
        ay=i+2
print(mini)
temp=llist[0]-llist[n-1]
if(temp<0):
        temp=-temp
if(mini>temp):
        mini=temp
        ax=1
        ay=len(llist)
print(ax,ay)