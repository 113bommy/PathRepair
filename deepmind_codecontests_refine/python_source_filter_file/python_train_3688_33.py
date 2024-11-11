a=int(input())
b=list(map(int,input().split()))
k,f=map(int,input().split())
sum=0
for i in range(f-k):
    sum+=b[i]
print(sum)
