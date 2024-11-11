K = int(input())
N = input()
print(N if len(N) <= K else N[:K] + '...')