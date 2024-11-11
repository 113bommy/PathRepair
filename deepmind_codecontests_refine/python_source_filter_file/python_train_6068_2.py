t = int(input())
 
for i in range(t):
    n = int(input())
    a = [0] + list(map(int, input().split()))
    
    ans = [a[i] - a[i-1] for i in range(1, n+1)]
    
    result = 0
    for i in range(2, n):
        if ans[i] < 0:
            result = result + (-1)*ans[i]
    if result <= a[1]:
        print("YES")
    else:
        print("NO")