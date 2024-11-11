for i in range(int(input())):
    n, s, t = map(int, input().split())
    if s > t:
        min = t
    else:
        min = s
    if min == n:
        print("1")
    else:
        print(min + 1)
