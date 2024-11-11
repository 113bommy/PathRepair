n=int(input())
sum=0
for i in range(n):
    p,q=map(int,input().split())
    if p<q:
        sum=sum+1
print(sum)