T = int(input())
while T > 0:
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    count = [0]*(2*k+2)
    for i in range(n//2):
        count[2] += 2
        x, y = sorted([arr[i], arr[n-i-1]])
        count[x+1] -= 1
        count[x+y] -= 1
        count[x+y+1] += 1
        count[y+k+1] += 1
    for i in range(2, len(count)):
        count[i] += count[i-1]
    print(min(count))
    T -= 1