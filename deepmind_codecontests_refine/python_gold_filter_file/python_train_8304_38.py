H,N = map(int, input().split())
A = list(map(int, input().split()))

print('No' if sum(A) < H else 'Yes')