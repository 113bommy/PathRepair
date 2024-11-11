from sys import stdin

def main():
    A = int(input())

    for a in range(A, 1001):
        sum_ = 0
        i = a
        while i > 0:
            sum_ += i % 10
            i = i // 10
        if not sum_ % 4:
            print(a)
            return

input = lambda: stdin.readline()
main()
