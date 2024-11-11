
n = int(input())
arr = [int(i) for i in input().split(' ')]
a = []

last = 0
running_length = 0

for i in arr:
    if i > last:
        running_length += 1
    else:
        a.append(running_length)
        running_length = 1
    last = i

if running_length > 0:
    a.append(running_length)

def canjoin(en, begin):
    if begin == len(a) - 1:
        return True
    return arr[en - 1] < arr[begin] or arr[en] < arr[begin+1]

best = max(a) + 1 if max(a) != len(arr) else len(arr)
start = 0
for i in range(len(a)-1):
    end = start + a[i] - 1

    if end == len(arr) - 1:
        best = max(best, a[i]);
    else:
        if a[i+1] == 1 and end+1 != len(arr) - 1:
            # 3 seq joins
            if arr[end] < arr[end+2] - 1:
                best = max(best, a[i] + a[i+2])

        if a[i] == 1 or a[i+1] == 1 or canjoin(end, end+1):
            best = max(best, a[i] + a[i+1])

    start = end + 1

print(best)
