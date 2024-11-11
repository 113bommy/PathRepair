a=int(input())
r=[]
for i in range((a)):
    x,y=map(int,input().split())
    r.append([x,y])
count=2
for i in range(1,len(r)-1):
    if(r[i][0]-r[i][1]>r[i-1][0]):
        count=count+1
    else:
        if(r[i][0]+r[i][1]<r[i+1][0]):
            count=count+1
            r[i][0]+=r[i][1]
print(count)            
    
    
    
        
