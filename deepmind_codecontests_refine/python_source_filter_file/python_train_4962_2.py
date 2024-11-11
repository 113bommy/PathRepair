n,a,b,c,t=map(int,input().split(" "))
s=map(int,input().split(" "))
s = list(s)
sum=n*a
for i in range(0,n):
    if(b<c):
        sum+=(s[i]-t)*(c-b)
print(sum)

    
