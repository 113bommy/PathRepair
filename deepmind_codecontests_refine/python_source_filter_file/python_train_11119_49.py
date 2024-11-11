
lst = list(int(input()) for _ in range(6))

print("Yay!" if lst[4] - lst[1] <= lst[5] else ":(")