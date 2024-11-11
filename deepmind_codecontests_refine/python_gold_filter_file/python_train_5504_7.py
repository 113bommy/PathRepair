n = int(input())
for _ in range(n):
    a = sum([int(input()) for _ in range(2)])
    print(a if a < 10**80 else 'overflow')