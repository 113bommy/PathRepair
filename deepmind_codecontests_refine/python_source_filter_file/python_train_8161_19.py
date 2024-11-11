def solve(n, k):
    for i in range(n):
        s = []
        for j in range(n):
            if i == j:
               s.append(str(k))
            else:
               s.append(0)
        print(' '.join(map(str, s)))



def main():
    n, k = list(map(int, input().split()))
    print(solve(n, k))


main()
