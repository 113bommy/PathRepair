T = int(input())
while (T):
    a, b = map(int, input().split())
    print(a * (len(str(b + 1)) - 1))
    T -= 1