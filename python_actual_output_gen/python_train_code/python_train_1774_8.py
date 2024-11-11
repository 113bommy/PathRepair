for _ in range(int(input())):
    n = int(input())
    arr = list(input())
    prev = n-1
    ans = 0
    for i in range(n-1,-1,-1):
        if arr[i]=='A':
            ans = max(ans,prev-i)
            prev = i
    print(ans)
