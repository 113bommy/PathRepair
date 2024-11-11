n, k = map(int, input().split())
s = list(input())
for i in range(len(s)):
    if ord(s[i]) - ord('a') > ord('z') - ord(s[i]):
        to = 'a'
    else:
        to = 'z'
    if abs(ord(to) - ord(s[i])) < k:
        k -= abs(ord(to) - ord(s[i])) 
     #   k += 1
        s[i] = to
    else:
        if to == 'z':
            s[i] = chr(ord(s[i]) + k)
        else:
            s[i] = chr(ord(s[i]) - k)
        k = 0
if k == 0:
    print(''.join(s))
else:
    print(-1)