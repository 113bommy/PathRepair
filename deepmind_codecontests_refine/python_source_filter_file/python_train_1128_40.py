N = int(input())
A = list(map(int, input().split()))
A = [a//400 for a in A]
l = len({0,1,2,3,4,5,6,7}&set(A))
S = sum(a>7 for a in A)
print(min(l, 1), l+S)