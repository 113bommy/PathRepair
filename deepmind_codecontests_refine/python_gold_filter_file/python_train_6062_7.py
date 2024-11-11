t = int(input())

while t:
    t -= 1
    m = list(map(int, input().split()))
    ar = list(map(int, input().split()))
    print(min(sum(ar), m[1]))
