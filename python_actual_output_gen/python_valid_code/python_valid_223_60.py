N = int(input())

while N > 0:
    if N % 7 == 0:
        print("Yes")
        exit()
    N -= 4

print("No")