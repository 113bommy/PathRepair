A = list(map(int, input().split()))
k = int(input())
print(sum(A)-max(A)+max(A)*2**k)
