import sys
input = sys.stdin.readline

'''

'''

def update_front(n, arr):
    for i in range(n-1):
        if arr[i][0] > arr[i+1][0]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
        else:
            break

def update_back(n, arr):
    for i in reversed(range(n-1)):
        if arr[i][0] > arr[i+1][0]:
            arr[i], arr[i+1] = arr[i+1], arr[i]
        else:
            break

def get_min(score):
    mn = float("inf")
    index = None
    for i, s in enumerate(score):
        if s < mn:
            index = i
            mn = s
    return index
n, k = map(int, input().split())
arr = [[int(v), i] for i, v in enumerate(input().split(), start=1)]
arr.sort()
score = []
ops = []
pre = arr[-1][0] - arr[-1][0]
for _ in range(k):
    arr[-1][0] -= 1
    arr[0][0] += 1
    ops.append((arr[-1][1], arr[0][1]))

    update_front(n, arr)
    update_back(n, arr)

    score.append(arr[-1][0] - arr[0][0])

#print(score)
j = get_min(score)

if j < pre:
    print(score[j], j+1)
    for i in range(j+1):
        print(*ops[i])
else:
    print(pre, 0)




