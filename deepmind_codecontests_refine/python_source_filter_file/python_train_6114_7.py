n,m=map(int,input().split())
seq=list(map(int,input().split()))
figpr=list(map(int,input().split()))
li=[]
for i in seq:
    if i in figpr:
        li.append(i)
        
li.sort()
for i in li:
    print(i,end=' ')