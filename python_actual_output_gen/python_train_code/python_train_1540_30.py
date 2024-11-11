n, c = map(int, input().split())
p = list(map(int, input().split()))
t = list(map(int, input().split()))

p_l, p_t = 0,0
for i in range(n):
    p_l += max(0, p[i] - c * sum(t[:i+1]))
    p_t += max(0, p[n - i - 1] - c * sum(t[n-i-1:]))
if p_l > p_t:
    print('Limak')
elif p_l == p_t:
    print('Tile')
else:
    print('Radewoosh')
