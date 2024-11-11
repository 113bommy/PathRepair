N = int(input())
A = list(map(int, input().split()))
print('Yes' if len(set(A)) == len(A) else 'No')