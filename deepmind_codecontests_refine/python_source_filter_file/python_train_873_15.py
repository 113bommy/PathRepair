n,k=map(int, input().split())
s = set('0123456789'[:k+1])
print(sum(set(input()) == s for _ in range(n)))