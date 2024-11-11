n = int(input())
O = ["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
while n>5:
    n = n >> 1
    n = n-2
print(O[n-3])