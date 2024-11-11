for _ in range(int(input())):
    n,k,z = map(int,input().split())
    arr = list(map(int,input().split()))
    pre = [0] * n
    pre[0] = arr[0]

    for i in range(1,n):
        pre[i] = pre[i-1] + arr[i]

    ans = 0
    for i in range(1,k):
        mv = min(z,(k - i + 1) // 2)    #take the less of the total number of back moves you can perform and the number of moves remaining that you can perform
        temp = pre[k - 2*mv] + (arr[i]+arr[i-1])*mv
        ans = max(temp,ans)
    print(ans)