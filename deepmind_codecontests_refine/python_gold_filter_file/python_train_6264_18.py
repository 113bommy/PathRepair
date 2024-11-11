import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
left = {}
right = {}
ls = list(map(int, input().split()))
for i in range(1, n-1):
    left[i] = i-1
    right[i] = i+1
left[0] = None
right[n-1] = None
left[n-1] = n-2
right[0] = 1
index = {}
for i in range(n):
    index[ls[i]] = i
for i in range(n, 1, -1):
    if left[index[i]]==index[i-1]:
        right[index[i-1]] = right[index[i]]
        left[right[index[i]]] = index[i-1]
    elif right[index[i]]==index[i-1]:
        left[index[i-1]] = left[index[i]]
        right[left[index[i]]] = index[i-1]
    else: print("NO"); break
else: print("YES")
