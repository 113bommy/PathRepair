t = int(input())
for _ in range(t):
    n, k = map(int, input().strip().split())
    arr = list(map(int, input().strip().split()))
    if n == 1:
        print(0)
    else:
        arr.sort(reverse=True)
        print(sum(arr[:k]))