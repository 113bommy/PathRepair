s=input()
def kmp_fail(p):
    m=len(p)
    fail=m*[0]
    k=0
    j=1
    while j<m:
        if p[j]==p[k]:
            fail[j]=k+1
            j+=1
            k+=1
        elif k>0:
            k=fail[k-1]
        else:
            j+=1
    return fail
l=[-1]+kmp_fail(s)
le=l[-1]
if l.count(le)<2:
    le=l[le]
print(s[:le] if le>0 else 'Just a legend')