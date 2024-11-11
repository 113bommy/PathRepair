from collections import deque
def func(n, arr, d):
    arr = sorted(arr)
    median = arr[n // 2]
    res = 0
    for i in range(n):
        res += abs(median - arr[i]) // d
    print(res)
    return
    
if __name__ == "__main__":
    n, m, d = list(map(int, input().split()))
    temp = set()
    arr = deque([])
    for i in range(n):
        num = list(map(int, input().split())) 
        for j in range(m):
            temp.add(num[j]%d)
            arr.append(num[j])
    if len(temp) > 1:
        print(-1)
    else:
        func(n * m, arr, d)
    
