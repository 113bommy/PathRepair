n = int(input())
for x in range(int(n**0.5), 1, -1):
    if(n % x == 0):
        print(x, n // x)
        break
