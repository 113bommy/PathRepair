n=int(input())
h=0
i=1
x=0
while(n>0):
    x=(i*(i+1))//2
    if(n>x):
        h=h+1
    n=n-x
    i=i+1
    
print(h)
    
    
