for t in range(int(input())):
    n, x = list(map(int, input().split()))
    childs = 0
    for i in range(n - 1):
        a, b = map(int, input().split())
        if a == x or b == x:
            childs += 1
    print("Ayush" if childs < 2 or (n - childs - 1) % 2 else "Ashish")