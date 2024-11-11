N = int(input())
A = [int(i) for i in input().split()]
print('Yes' if len(set(A)) == N else 'No')