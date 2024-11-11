n=int(input())
a=sorted(list(map(int,input().split())))+[3001]
for i in range(n):
    if a[i+1]-a[i]>1:
        print(a[i]+1)
        exit()
