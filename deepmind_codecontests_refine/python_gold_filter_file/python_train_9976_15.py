x = int(input())
print(max(i**j for i in range(32) for j in range(2, 10) if i**j <= x))