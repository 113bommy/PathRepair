p = int(input())

for i in range(2, p):
    if p % i == 0:
        print(str(i) + str(p//i))
        break