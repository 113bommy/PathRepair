k=int(input())
o=[*map(int,input().split())]
list1=[0]*k
y=0
for j in range(k):
    y=max(y,o[j]+1)
    list1[j]=y
for z in range(0,k):
    list1[z-1]=max(list1[z-1],list1[z]-1)
list2=zip(list1,o)
print(sum(x-f -1 for x,f in list2 ))
