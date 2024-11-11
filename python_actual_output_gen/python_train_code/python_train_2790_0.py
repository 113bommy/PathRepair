
j,k = map(int,input().split(" "))
li = list(map(int,input().split(" ")))

li.insert(0,0)
li= list(set(li))
li.sort()
l=max(j,k)
t = min(j,k)
i=1
while i<=t:
    if(i<len(li)):
        print(li[i]-li[i-1])
        
    else:
        print(0)
    i=i+1
