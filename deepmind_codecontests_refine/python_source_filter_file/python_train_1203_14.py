s = '0'+input()+'1'
l = 'AEIOUY'
i, k, mx, p, ls = 0, 0, 0, 0, 0
while i<len(s):
    if s[i] in l:
        k=(i-p)
        p = i
        if mx<k:
            mx = k
            ls = 1
    i+=1
if ls==1:
    print(mx)
else:
    print(len(s)-1)