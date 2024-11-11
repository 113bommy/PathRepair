n = int(input())
L = list(map(int, input().split()))
L.sort()
print(L[n//2])