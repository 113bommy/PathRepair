t=int(input())
a=list(map(int,input().strip().split(" ")))[:t]
c=0
for i in range(len(a)):
    c+=a[i]   
avg=c//2
c1=0
for j in range(len(a)):
    c1+=a[j]
    if c1>=avg:
        print(j+1)
        break
