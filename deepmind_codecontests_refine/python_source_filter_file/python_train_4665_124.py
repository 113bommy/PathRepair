N = int(input())
D = list(map(int, input().split()))
D.sort()
print(D[N//2 + 1] - D[N//2])