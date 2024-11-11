a,b=map(int,input().split())
n=int(input())
k=0
for i in range(n) :
    
    z,x,y=map(int,input().split())
    d=(z**2+x**2)**(1/2)
    if d+y<=b and d-y>=b-a  :
        k=k+1
print(k)
    
