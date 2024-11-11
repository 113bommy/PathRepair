s = input()
n = len(s)
alph = {'A', 'O', 'E', 'U', 'Y', 'I'}
last_ind = 0
while (last_ind < n):
    if (last_ind >= n or s[last_ind] in alph):
        break
    last_ind += 1
if last_ind == n:
    print(n)
else:
    ans = last_ind + 1
    for i in range(last_ind + 1, n):
        if s[i] in alph:
            ans = max(ans, i - last_ind)
            last_ind = i
    if s[-1] not in alph:
        print(max( ans, n - last_ind))
    else:
        print(ans)