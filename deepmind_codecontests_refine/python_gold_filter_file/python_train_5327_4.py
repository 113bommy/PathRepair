N = int(input())
ans = []

for i in range(N):
    n, s, t = [int(i) for i in input().split()]
    if s == t == n:
        ans.append('1')
    else:
        ans.append(str(n - min(s,t) + 1))
print('\n'.join(ans))
