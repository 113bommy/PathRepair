n = int(input())
for i in range(n):
    a, b = map(int, input().split())
    print(min(min(a, b)*2, max(a, b))**2)