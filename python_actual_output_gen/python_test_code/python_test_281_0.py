n=int(input())
for i in range(N):
    i = i + 1
    for j in range(N-i):
        j = i+j+1
        for k in range(9):
            if i % (2**(k+1)) != j % (2**(k+1)):
                print(k+1, end=" ")
                break
    print()
