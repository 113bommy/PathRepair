A, B, K = map(int, input().split())
*p, = range(A, min(B, A+K))
*q, = range(max(A, B-K)+1,B+1)
print(*sorted(set(p+q)), sep='\n')