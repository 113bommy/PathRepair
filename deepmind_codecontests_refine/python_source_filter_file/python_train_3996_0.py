n=int(input())
l=list(map(int,input().split()))
g=l[0]
m=int(input())
S=''
for i in range(m) :
    a,b=map(int,input().split())
    t=max(l[0],l[a-1])
    S+=str(t-g+1)+'\n'
    l[0]=t+b
    l[a-1]=t+b
print(S)
    
