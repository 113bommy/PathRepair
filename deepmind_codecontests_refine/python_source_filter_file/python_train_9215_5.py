n=int(input())
l=[*input()]
res=0
m=[0,0]
k=0
z=0
for i in range(n):
    z,k=0,0
    for j in range(i,n,2):
        if l[j]=='L' :
            k+=1
        if l[j]=='R' :
            k-=1
        if l[j]=='U' :
            z+=1
        if l[j]=='D' :
            z-=1
        if k==0 :
            m[0]=1
        else :
            m[0]=0
        if z==0 :
            m[1]=1
        else :
            m[1]=0
        if m==[1,1]:
            res+=1
print(res)
        
        
        
