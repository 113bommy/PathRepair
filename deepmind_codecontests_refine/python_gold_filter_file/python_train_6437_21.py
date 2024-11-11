S = list(input())

def check(x):
    #print(S[len(S)-x:x])
    for y in S[len(S)-x:x]:
        if y != S[len(S)-x]: break
    else:
        return True
    return False

def bisect(l,r):
    if r - l == 1: return l
    mid = (l+r) // 2
    if check(mid) == False:
        return bisect(l,mid)
    else:
        return bisect(mid,r)
print(bisect(0,len(S)+1))

