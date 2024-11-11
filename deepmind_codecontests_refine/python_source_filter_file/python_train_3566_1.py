def contiguous_subset(arr):
    # Helper function to compute the maximum subset sum of an array.
    cur = 0
    best = 0
    for i in arr:
        cur = max(cur + i, 0)
        best = max(cur, best)
    return best

def best_evens(arr):
    if len(arr) == 1:
        return 0
    left_flip = [arr[i-1] - arr[i] for i in range(2, len(arr), 2)]
    right_flip = [arr[i+1] - arr[i] for i in range(0, len(arr) - 1, 2)]
    sum_evens = sum(arr[::2])
    return sum_evens + max(contiguous_subset(left_flip), contiguous_subset(right_flip))

t = int(input())
for _ in range(t):
    a = input()
    a = [int(i) for i in input().split()]
    print(best_evens(a))

