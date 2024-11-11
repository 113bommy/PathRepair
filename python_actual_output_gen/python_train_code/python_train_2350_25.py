t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    print(a * (len(str(b))-1))