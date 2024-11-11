from collections import deque


t = int(input())
for _ in range(t):
    n = int(input())
    arr = [int(__) for __ in input().split()]
    ans = []

    arr_sorted = arr[:]
    arr_sorted.sort()

    for _ in range(n):
        if arr[_] != arr_sorted[_]:
            idx = arr[_:].index(arr_sorted[_])+_
            ans.append([_+1,idx+1,idx-_+1])

            deq_rotated = deque(arr[_:idx+1])
            deq_rotated.rotate(_-idx)
            arr = arr[:_] + list(deq_rotated) +arr[idx+1:]
    
    print(len(ans))
    for _ in ans:
        print(_)