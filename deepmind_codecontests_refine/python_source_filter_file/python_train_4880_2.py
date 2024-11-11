n = int(input())
for i in range(n):
    left = right = []
    arr = map(int, input().split())
    for a in arr:
        if len(left) == 0 or left[-1] < a:
            left.append(a)
        elif len(right) == 0 or right[-1] < a:
            right.append(a)
        else:
            break
    if len(left) + len(right) == 10:
        print("YES")
    else:
        print("NO")