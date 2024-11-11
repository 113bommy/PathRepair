import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    s = sum(arr)
    for i in range(n, 1, -1):
        if s % i == 0:
            cursum = s//i
            cur = 0
            ok = True
            for j in range(n):
                cur += arr[j]
                if cur > cursum:
                    ok = False
                    break
                elif cur == cursum:
                    cur = 0
                
            if ok:
                print(n-i)
                break
    
    if not ok:
        print(n)
