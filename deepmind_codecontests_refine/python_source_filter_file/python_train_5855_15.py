n = int(input())
for i in range(n, n+1):
    if n % i == 0:
        print(str(i)+str(n // i))
        break
