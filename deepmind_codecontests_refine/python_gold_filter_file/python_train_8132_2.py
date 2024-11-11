nQ = int(input())
for i in range(nQ):
    k, x = map(int, input().split())
    print(x + (k - 1) * 9)
