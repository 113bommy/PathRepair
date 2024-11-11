n = int(input())
A = list(map(int, input().split()))
s = input()
ans = []
st = A[:1]
for i, a in enumerate(A[1:]):
  if s[i] == '1':
    st += [a]
  else: 
    ans += sorted(st)
    st = [a]
ans += sorted(st)
print('YES' if sorted(ans) == ans else 'NO')