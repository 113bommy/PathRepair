N = int(input())
mod = 10**9+7

def check(s):
    for i in range(4):
        l=list(s)
        if i>0:
            l[i-1],l[i]=l[i],l[i-1]
        if "".join(l).count("AGC"):
            return False
    else:
        return True

memo=[dict() for _ in range(N)]
def dfp(i,seq):
    if i==N:
        return 1
    if seq in memo[i]:
        return memo[i][seq]
    ret=0
    for s in ["A","G","C","T"]:
        if check(seq+s):
            ret=(ret+dfp(i+1,seq[1:]+s))%mod
    memo[i][seq] = ret
    return ret

print(dfp(0,"TTT"))