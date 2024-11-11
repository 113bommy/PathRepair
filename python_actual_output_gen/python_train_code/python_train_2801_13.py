x,y,a,b=map(int,input().split())
ans=[]
for i in range(a,x+1):
    for j in range(b,i+1):
        #print(i,j)
        if i>j:
            ans.append([i,j])
print(len(ans))
for x in ans:
    print(x[0],x[1])