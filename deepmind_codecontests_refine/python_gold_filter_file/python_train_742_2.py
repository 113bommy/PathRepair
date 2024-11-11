#1165E

def minimizeLR(n, a, b):
    for i in range(0, n):
        a[i] = a[i] * (i+1)*(n-i)

    min_vals = [a*b for a, b in zip(reversed(sorted(a)),sorted(b))]

    print(sum(min_vals) % 998244353)
    


if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split(" ")))
    b = list(map(int, input().split(" ")))
    minimizeLR(n, a, b)