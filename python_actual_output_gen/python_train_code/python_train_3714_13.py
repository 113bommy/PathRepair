s = list(input())
k = int(input())
n = len(s)
for i in range(n-1):
    d = ord('z')-ord(s[i])+1
    if d<=k:
        s[i] = 'a'
        k -= d

x = ord(s[-1])+k%26
if x>ord('z'):x-=26
s[-1] = chr(x)


print(''.join(s))
