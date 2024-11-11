n = int(input())
k = n % 10
if (n <= 5):
    print(n - (n % 10))
else:
    print(n + (10 - (n%10)))
