n,k=map(int,input().split())
a=list(map(int,input().split()))

a.sort()
flag=0;j=0

for i in range(n):
    temp=a[i]-flag
    if temp>0 and j<k:
        print(temp)
        flag+=temp
        j+=1


for i in range(k-j):
    print(0)
