from collections import defaultdict

N = int(input())
array = [int(x) for x in input().split()]

def stuff(N, array):
    L = N / 2
    d = defaultdict(int)
    for x in array:
        d[x] += 1
        if d[x] > L:
            return False
    return True

print("YES" if stuff(N, array) else "NO")
