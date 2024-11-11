import sys
input = sys.stdin.buffer.readline

for _ in range(int(input())):
    n = int(input())

    if n == 1:
        print("a")
    elif n == 2:
        print("ab")
    elif n % 2:
        print("a"*(n//2)+"bc" + "a"*(n//2-1))
    else:
        print("a"*(n//2) + "b" + "a"*(n//2-1))