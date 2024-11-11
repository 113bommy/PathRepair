for _ in range(int(input())):
    y = list(map(int, input().split()))
    if sum(y) % 3 == 0 and sum(y) // 3 >= max(y):
        print("YES")
    else:
        print("NO")
