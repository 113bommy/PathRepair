n, m = map(int, input().split())
A = list(map(int, input().split()))
sa = sum(A)
print('Yes' if len([a for a in A if a>=sa/(4*m)])>=m else 'No')