import sys
input = sys.stdin.readline
n, d = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
score = a[d-1] + b[0]
current_pos = 1
j = n - 1
k = 1
i = 0
while i != d - 1:
    if a[i] > score:
        current_pos += 1
        k += 1
    else:
        if a[i] + b[j] >= score:
            current_pos += 1
        elif a[i] + b[j] < score:
            j -= 1
    i += 1
print(current_pos)