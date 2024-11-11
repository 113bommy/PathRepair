n = int(input())
a = n**2
b = n//2
for i in range(0, b*n, b):
    for j in range(b):
        print(i+j+1, end=" ")
    for j in range(b):
        print(a-i-j, end=" ")
    print("")