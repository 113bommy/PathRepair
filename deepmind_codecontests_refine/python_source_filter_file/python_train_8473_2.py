n=int(input())
a=list(map(int,input().split()))
count=[0]*7
for i in range(n):
    count[a[i]-1]+=1
if count[4]==0 and count[6]==0 and count[1] >= count[2] and count[0]==count[3]+count[5] and count[1]+count[2]==count[3]+count[5]:
    for j in range(count[3]):
        print("1 2 4")
    count[1]-=count[3]
    
    for k in range(count[1]):
        print("1 2 6")
    
    for l in range(count[2]):
        print("1 3 6")
        
        
else:
    print(-1)