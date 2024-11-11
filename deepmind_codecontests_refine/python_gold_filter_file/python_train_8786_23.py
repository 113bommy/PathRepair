n=int(input())
l=list(map(int,input().split()))
x,y=map(int,input().split())
s=sum(l)
s1=0
for i in range(n) :
    s-=l[i]
    s1+=l[i]
    if s<=y and s1<=y and s>=x and s1>=x :
        print(i+2)
        exit()
print(0)
        
    
