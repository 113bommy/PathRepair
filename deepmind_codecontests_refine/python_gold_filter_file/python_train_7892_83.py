b = list(map(int, input().split()))
k = int(input())
print(sum(b) + max(b)*(2**k-1) )