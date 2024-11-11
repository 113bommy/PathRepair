n=int(input())
arr=[int(x) for x in input().split()]

for i in range(n):
    arr[i]-=1

for i in range(n):
    pos=i
    stat=[False for x in range(n)]
    while(stat[pos]!=True):
        stat[pos]=True
        pos=arr[pos]
    print(pos,end=' ')