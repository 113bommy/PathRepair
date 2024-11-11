for _ in range(int(input())):
    n = int(input())
    A = [int(a) for a in input().split()]
    print("YES" if A[0] > A[n - 1] else "NO")