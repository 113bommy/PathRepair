# cook your dish here
r,d=map(int,input().strip().split(' '))
n=int(input())
k=0
for i in range(n):
    x,y,r1=map(int,input().strip().split(' '))
    dis=pow(x*x+y*y,.5)
    if(dis+r1<=r and dis-r1>=d):
        k+=1
print(k)