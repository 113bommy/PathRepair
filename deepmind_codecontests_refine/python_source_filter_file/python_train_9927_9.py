n = int(input())
arr = list(map(int, input().split()))
ab = sorted(arr)
t = [i for i in range(n) if arr[i] != ab]
if len(t) < 3:
    print("YES")
else:
    print("NO")
