N = int(input())
A = tuple(map(lambda num: min(2, format(int(num), "b")[::-1].index("1")), input().split()))
n2 = A.count(2)

print("Yes" if n2 * 2 >= N - N % 2 or sum(A) >= N else "No")