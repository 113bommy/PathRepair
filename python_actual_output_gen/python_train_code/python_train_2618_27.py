for t in range(int(input())):
    a, b = map(int, input().split())
    print(min(min(a, b)*2, max(a, b))**2)