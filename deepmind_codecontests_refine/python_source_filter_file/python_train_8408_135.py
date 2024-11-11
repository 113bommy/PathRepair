X = int(input())

for A in range(100):
    for B in range(-100, 100):
        if A ** 5 - B ** 5 == X:
            print(A, B)
            exit()
