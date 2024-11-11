n = int(input())
lst = list(map(int, input().split()))
mn = lst[0]
c = 0
index = 1

for i in range(1, len(lst)):
    if lst[i] < mn:
        c = 0
        mn = lst[i]
        index = i+1
    elif lst[i] == mn:
        c += 1

if c > 0:
    print("Still Rozdil")
else:
    print(index)