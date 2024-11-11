n = int(input())
for x in range(int(n**0.5), 0, -1):
    if(n % x == 0):
        print(x, n // x)
        break
