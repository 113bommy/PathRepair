n=int(input())
a=list(map(int,input().split()))
a.sort()
sum,d=0,0
for i in range(n):
    if a[i]>=sum:
        d+=1
    sum+=a[i]
print(d)