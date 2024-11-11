n = int(input())
a = list(map(int, input().split()))

def solve(a, n):
    first = False
    for i in range(1, n):
        if a[i-1] > a[i] and first:
            first = True

        if first and a[i-1] < a[i]:
            return False

    return True

print("Yes") if solve(a, n) else print("No")



