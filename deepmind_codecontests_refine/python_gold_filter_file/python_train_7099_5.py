for _ in range(int(input())):
    n=int(input())
    a=[int(x) for x in input().split()]
    for i in range(n):
        j=a[i]
        cnt=1
        while (j<=n and j!=i+1):
            j=a[j-1]
            cnt+=1
        print(cnt,end=" ")
    print()