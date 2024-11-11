n,m=map(int,input().split())
list1=[111]*(101)
list2=[0]*(101)
for i in range(m):
    l,r,t,c=map(int,input().split())
    x=r-l+1
    for j in range(l,r+1):
        if(list1[j]>t):
            list1[j]=t
            list2[j]=c
        # elif(list1[j]==t and list2[j]<c):
        #     list2[j]=c
            
print(sum(list2))
        
    