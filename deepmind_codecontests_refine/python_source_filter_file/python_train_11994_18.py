
def getChar(x, y):
    opts = ['a', 'b', 'c']
    if x in opts: opts.remove(x)
    if y in opts: opts.remove(y)
    
    return opts[0]

def findBS(s):
    length = len(s)
    opts = ['a', 'b', 'c']
    
    if length == 1:
        if '?' in s: print(-1)
        else: print(s)
        return
    
    for i in range(len(opts)):
        if s[0] == '?' and s[1] != opts[i]:
            s[0] = opts[i]
        if s[length-1] == '?' and s[length-2] != opts[i]:
            s[length-1] = opts[i]
    
    for i in range(1, length-1):
        if s[i] == '?': s[i] = getChar(s[i-1], s[i+1])
        if s[i] == s[i-1] or s[i] == s[i+1]:
            print('-1')
            return
            
    if '?' in opts:
        print(-1)
    print(''.join(s))
    
t = int(input())
for _ in range(t):
    s = list(input().rstrip())
    findBS(s)
    