for _ in range(int(input())):
    n, m = map(int, input().split())
    arr = [list(input().split()) for _ in range(n)]

    ans = "YES"
    for i in range(n):
        for j in range(m):
            curr_max = 4
            if i == 0 or i == n - 1:
                if j == 0 or j == n - 1:
                    curr_max -= 2
                else:
                    curr_max -= 1
            else:
                if j == 0 or j == n - 1:
                    curr_max -= 1
            
            if int(arr[i][j]) > curr_max:
                ans = "NO"
                break
            else:
                arr[i][j] = curr_max
        
        if ans == "NO":
            break
    
    if ans == "NO":
        print(ans)
    else:
        print(ans)
        for i in range(n):
            print(*arr[i])