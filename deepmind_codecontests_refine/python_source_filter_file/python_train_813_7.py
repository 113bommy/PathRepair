h,w = map(int,input().split())
s = [input() for _ in range(h)]

for i in range(h):
    l = ''
    for j in range(w):
        if s[i][j] == '#':
            l += s[i][j]
        else:
            l += str(sum([t[max(0,j-1):min(j+2,w)].count('#')\
                     for t in s[max(0,i):min(h,i+2)]]))
    print(l)