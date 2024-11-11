N = int(input())
A = [0]+list(map(int, input().split()))
print(sorted(range(len(A)), key=lambda k: A[k])[1:])
