x = int(input())
print(max(i**j for i in range(1, 32) for j in range(1, 32) if i**j <= x))