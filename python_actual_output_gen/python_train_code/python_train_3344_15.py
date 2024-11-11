n=input()
x=list(input().split())
x.sort()
ans=0
for i in range(1,len(x),2):
    ans+=int(x[i])-int(x[i-1])
print(ans)    
    
