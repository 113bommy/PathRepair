# %%
n = int(input())
x = input()

num_of_1 = x.count("1")

first = int(x, 2)

def f(x):
    if x == 0:
        return 0
    return 1 + f(x % bin(x).count('1'))

if num_of_1 == 1:
    for i in range(n):
        if x[i] == '1':
            print(0)
        elif i == n-1:
            print(2)
        else:
            print(1)
    exit()

first_one, first_zero = first % (num_of_1 - 1), first % (num_of_1 + 1)

for i in range(n):
    if x[i] == "0":
        print(1 + f((first_zero + pow(2, n-i-1, num_of_1 + 1)) % num_of_1 + 1))
    else:
        print(1 + f((first_one - pow(2, n-i-1, num_of_1 - 1)) % num_of_1 - 1))
