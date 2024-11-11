def gennextnum(nextnum):
    s = str(nextnum)
    sevens = 0
    first4 = 0
    for c in s:
        if c == '7':
            sevens += 1
        else:
            first4 = len(s) - s[::-1].index(c) - 1
    if sevens == len(s):
        ret = ''
        for i in range(len(s)+1):
            ret+='4'
        return int(ret)
    else:
        ret = s[:first4] + '7'
        for i in range(first4,len(s)-1):
            ret+= '4'
        return int(ret)

l, r = map(int, input().split())
nextnum = 4
'''
for i in range(10):
    print(nextnum)
    nextnum = gennextnum(nextnum)
'''
score = 0
i = l
prevnum = 4
while i < r+1:
    while i > nextnum:
        prevnum = nextnum
        nextnum = gennextnum(nextnum)
    if nextnum + 1 > r:
        print(i, r, nextnum)
        score += (r - i + 1)*nextnum
        break
    else:
        score += (nextnum - i + 1) * nextnum
        i = nextnum + 1
    print(nextnum, score)
print(score)
