n=int(input())
a=[0]+sorted(list(map(int,input().split())))+[13001]
for i in range(n+1):
    if a[i+1]-a[i]>1:
        print(a[i]+1)
        exit()
