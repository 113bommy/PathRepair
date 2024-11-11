

def main():
    n = int(input())
    for a in range((n + 1) // 2 - 1, 0, -1):
        b = n - a
        if check(a, b):
            print(a, b)
            return


def check(a, b):
    for i in range(2, min(a, b)):
        if a // i == 0 and b // i == 0:
            return False
    return True

main()
