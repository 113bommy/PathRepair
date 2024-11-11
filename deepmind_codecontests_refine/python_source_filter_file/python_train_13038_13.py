def lights(n,m):
    row=n//2;
    count=0;
    count+=row*m;
    if n%2==1:
        count+=m//2;
    if m%2==1:
        count+=1;
    return count;
    
t=int(input())

for i in range(t):
    n,m=map(int,input().split());
    print(lights(n,m));
