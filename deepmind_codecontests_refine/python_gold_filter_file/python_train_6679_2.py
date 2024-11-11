import sys
def main():
    n = int(sys.stdin.readline())
    a = input()
    out = []
    index = None
    f = 0
    number = 1
    if n % 2 == 1:
        for i in range(n - 1):
            if (i + 1) % 2 == 1 and a[i] == a[i + 1]:
                index = i
                break
        else:
            index = n - 1
    for i in range(n):
        if i < f or i == index:
            continue
        if number % 2 == 0 or (number % 2 == 1 and i < n - 1 and a[i] != a[i + 1]):
            out += a[i]
            number += 1
    sys.stdout.write(str(n - len(out)) + '\n')
    for i in out:
        sys.stdout.write(str(i))
main()
