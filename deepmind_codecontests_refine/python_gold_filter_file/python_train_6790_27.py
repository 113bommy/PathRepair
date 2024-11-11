T = int(input())
for _ in range(T):
    a, b = map(int,input().split())
    print(a * (len(str(b + 1)) - 1))