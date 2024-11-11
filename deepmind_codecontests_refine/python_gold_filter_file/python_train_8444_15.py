#y,b,r;    y,y+1,y+2;
a=list(map(int,input().split()))
b=max(a)
j=[]
for i in range(b):
    k=[i,i+1,i+2]
    if a[0]>=k[0] and a[1]>=k[1] and a[2]>=k[2]:
        j.append(k)
print(sum(j[-1]))
        
    
    

