def prefix(s):
    v = [0]*len(s)
    for i in range(1,len(s)):
        k = v[i-1]
        while k > 0 and s[k] != s[i]:
            k = v[k-1]
        if s[k] == s[i]:
            k = k + 1
        v[i] = k
    return v

n = int(input())
n-=1
s1 = input()
s2 = input()
opos = {'W':'E', 'E':'W', 'N':'S', 'S':'N'}
s3 = ''
for elem in s2:
    s3 += opos[elem]
    
s3[::-1]
s = s3 + '$' + s1

a = prefix(s)[2 * n]
if a == 0: print('YES')
else: print('NO')

