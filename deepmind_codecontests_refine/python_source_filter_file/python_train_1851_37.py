
n,d = map(int,input().split())
sum=0
for i in range(n):
    x,y = map(int,input().split())
    if(x*x+y*y<=d):
        sum+=1
print(sum)
