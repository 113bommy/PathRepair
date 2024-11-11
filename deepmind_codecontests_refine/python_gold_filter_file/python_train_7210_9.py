n=int(input())
l=list(map(int,input().split()))
sum1=0
i=0
while True:
    sum1=sum1+l[i%7]
    if(sum1>=n):
        print((i%7)+1)
        break
    i=i+1