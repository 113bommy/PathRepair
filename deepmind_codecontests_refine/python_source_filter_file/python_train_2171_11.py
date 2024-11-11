a,b,c=map(int,input().split())
if a==b==c:print(-(a%2==0));exit()
r=0
while(a-1)*(b-1)*(c-1)%2:a,b,c,r=(b+c)/2,(c+a)/2,(a+b)/2,r+1
print(r)