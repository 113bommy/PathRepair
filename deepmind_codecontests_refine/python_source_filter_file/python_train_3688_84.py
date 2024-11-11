n=int(input())
d=list(map(int,input().split()))
a,b=map(int,input().split())
temp=b-a
sum1=0
for i in range(temp):
    sum1=sum1+d[i]
print(sum1)