X = int(input())

for A in range(1000):
    for B in range(-500, 500):
        if A**5-B**5 == X:
            print(A, B)
            exit()
