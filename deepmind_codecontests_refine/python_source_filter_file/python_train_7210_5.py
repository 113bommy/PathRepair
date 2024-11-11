n = int(input())
lis = list(map(int,input().split()))
lis = lis*10000

for i in range(len(lis)):
    n = n-lis[i]
    if n<=0:
        if i == 6:
            print(7)
        else:
            print((i+1)%7)
        break
    else:
        continue