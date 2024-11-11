X = int(input())

for A in range(100):
    for B in range(-50, 50):
        if A**5-B**5 == X:
            print(A, B)
            exit()
