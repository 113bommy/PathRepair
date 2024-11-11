n=int(input())
x=list(map(int,input().split()))
a,b=map(int,input().split())
c=abs(b-a)
sum=0
if(c==0):
    print("0")
else:
    for i in range(0,c):
        sum=sum+x[i]
    print(sum)    