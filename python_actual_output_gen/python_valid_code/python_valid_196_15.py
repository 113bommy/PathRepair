x = [int(x) for x in input().split()]

total_notebooks = 0

total_notebooks += (((2*x[0]) // x[1]) + 1 if (2*x[0])%x[1] > 0 else 0)
total_notebooks += (((5*x[0]) // x[1]) + 1 if (5*x[0])%x[1] > 0 else 0)
total_notebooks += (((8*x[0]) // x[1]) + 1 if (8*x[0])%x[1] > 0 else 0)

print(total_notebooks)