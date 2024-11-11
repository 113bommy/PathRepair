from sys import stdin, stdout
def main():
    A = list(map(int, stdin.readline().strip().split()))
    A[:] = sorted(A, reverse = True)
    m = max(A) - 1
    c = 0
    for i in A[1:]:
        c += m - i
    stdout.write(f'{c}')

if __name__ == '__main__':
    main()


