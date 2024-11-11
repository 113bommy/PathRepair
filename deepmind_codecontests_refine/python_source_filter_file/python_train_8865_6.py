t = int(input())
for i in range(t):
    n,k = map(int, input().split())
    if k % 3 != 0:
        if n % 3 == 0:
            print("Bob")
        else:
            print("Alice")
    else:
        if n % (k+1) == k:
            print("Alice")
        elif n % 3 == 0:
            print("Bob")
        else:
            print("Alice")