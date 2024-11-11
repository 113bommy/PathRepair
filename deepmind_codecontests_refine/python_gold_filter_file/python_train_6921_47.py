n=int(input())
a=list(map(int,input().split()))
a.sort()
summ,d=0,0
for i in range(n):
    if a[i]>=summ:
        d+=1
        summ+=a[i]
print(d)