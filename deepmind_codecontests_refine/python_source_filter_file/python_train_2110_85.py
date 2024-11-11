t = int(input())

n_values = [int(input()) for i in range(t)]

for value in n_values:
    for i in range(1, value+1):
        print(i, end='')
    print()