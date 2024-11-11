s = [c for c in input()]
k = int(input())
l = len(s)
for i in range(l):
    t = ord('z')-ord(s[i])+1
    if t <= k:
        k -= t
        s[i] = 'a'
s[-1] = chr((ord(s[-1]) - ord('a') + k) % 26 + ord('a'))
print(''.join(s))