t,a,k = map(int, input().split())
T = max(t - k,0)
k -= T - t
A = max(a - k,0)
print(T,A)