def sr(s):
    for i in range(1, len(s)):
        val = s[i]
        j = i - 1
        while (j >= 0) and (s[j] > val):
            s[j+1] = s[j]
            j = j - 1
        s[j+1] = val
    return(s)
r=int(input())
b=input().split()
def g (f) :
    for i in range(len(f)) :
        f[i]=int(f[i])
    return(f)
b=g(b)
b.sort()
if b[0]<b[r//2] :
    print("YES")
else :
    print("NO")
