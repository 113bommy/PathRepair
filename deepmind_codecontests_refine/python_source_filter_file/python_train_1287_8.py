n = int(input())
a = list(map(int, input().split()))
suma = sum(a)
print(max(suma % n, n - suma % n))
