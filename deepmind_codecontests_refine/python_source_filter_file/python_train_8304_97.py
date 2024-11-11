H, _ = map(int, input().split(" "))
print("Yes" if sum(map(int, input().split(" "))) <= H else "No")