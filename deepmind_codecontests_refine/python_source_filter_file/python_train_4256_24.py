N = int(input())
L = list(map(int, input().split()))
L.sort()
sum(L[::2])