t = int(input())
a = list(map(int, input().split()))

min_idx = 0
for i in range(1, t):
    if a[i] < a[min_idx]:
        min_idx = i
res = True
for i in range(t):
    if i != min_idx and a[i] == a[min_idx]:
        res = False
        break

if res:
    print(min_idx+1)
else:
    print("Still Rozdil")
