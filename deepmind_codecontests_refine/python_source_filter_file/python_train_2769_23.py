x,y=map(int,input().split(" "))

c=min(x,y)
s=1
i=1

while(s<=c):
    s=s*i
    i=i+1
    
print(s)