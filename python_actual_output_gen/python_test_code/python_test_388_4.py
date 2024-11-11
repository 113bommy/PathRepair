n,x=map(int,input().split()) 
a=sorted(list(map(int,input().split()))) 
k=a[-1] 
count=0 
if x in a:
    count+=1 
while(k>=0):
    if k not in a:
        if(k!=x):
            count+=1 
    k-=1 
print(count)
    
