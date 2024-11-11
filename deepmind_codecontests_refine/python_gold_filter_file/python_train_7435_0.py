n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))

def vol(x, y):
    if 2 * x >= y:
        a = y // 2
        return a * (y - a) or -1
    else:
        return -1

print(sum(map(vol, a, b)))
