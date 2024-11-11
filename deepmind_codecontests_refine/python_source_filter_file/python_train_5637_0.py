n = int(input())
arr = list(map(int, input().split()))
arr.sort()
pair = []
for i in range(n//2):
    for j in range(i+1, n):
        pair.append(arr[i]+arr[j])

x = {}
for i in pair:
    if i not in x:
        x[i] = 1
    else:
        x[i] += 1

print(max(x.items(), key=lambda x:x[1])[1])
