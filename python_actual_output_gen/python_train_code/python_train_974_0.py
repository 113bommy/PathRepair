n=int(input())
d=list(map(int,input().split()))
d_sum=sum(d)
sq=0
for i in range(n):
    sq+=d[i]**2
print(d_sum**2-sq)