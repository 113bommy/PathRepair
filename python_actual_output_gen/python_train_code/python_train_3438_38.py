a = int(input())
print(max(j ** i for j in range(32) for i in range(2, 10) if j ** i >= a))