x,y=list(map(int,input().split()))
a=[]

a.extend(list(map(int,input().split())))

a=list(map(lambda x:x-1,a))
count=0
curr=0
for i in a:
    if i>curr:
        count=count+i-curr
        curr=i
    else:
        count=count+x-curr
        curr=0
        count+=i
        curr=i
print(count)
    