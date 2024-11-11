h, w, n = map(int, input().split())
sr, sc = map(int, input().split())
s = input()
t = input()
sr -= 1; sc -= 1
 
L=0; R=w-1; U=0; D=h-1;
is_drop = False
for i in range(n)[::-1]:
    if t[i] == 'U': D = min(D+1, h-1)
    if t[i] == 'D': U = max(U-1, 0)
    if t[i] == 'L': R = min(R+1, w-1)
    if t[i] == 'R': L = max(L-1, 0)
    if s[i] == 'U': U += 1
    if s[i] == 'D': D -= 1
    if s[i] == 'L': L += 1
    if s[i] == 'R': R -= 1
    if R < L or D < U: is_drop = True
    if (not L <= sc <= R) or (not U <= sr <= D):  is_drop = True

print( "NO" if is_drop else "YES" )
