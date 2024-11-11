
def findall(s, mn):
    pos = []
    for i in range(len(s)):
        if s[i] == mn:
            pos.append(i)
    return pos

def build(pos):
    global s
    if (len(s)-pos)%2==1:
        return s[pos:]+s[:pos][::-1]
    else:
        return s[pos:]+s[:pos]




for i in range(int(input())):
    a = int(input())
    s = input()
    mn = min([i for i in s])
    pos = findall(s,mn)
    if len(pos) == 1:
        print(build(pos[0]))
        print(pos[0]+1)
    else:
        temp = build(pos[0])
        ans = pos[0]
        for i in pos:
            bld = build(i)
            if bld<temp:
                temp = bld
                ans = i
        print(temp)
        print(ans+1)
