x,y = map(int ,input().split())
i,ans,prev=0,0,1
while i < int(x):
    a,b = map(int ,input().split())
    ans+= (a-b)%y + b-a+1
    prev = b+1
    i+=1
print(ans)    

#BY Mahmoud Farid 
# mail : mahmoudfaridnsr@gmail.com