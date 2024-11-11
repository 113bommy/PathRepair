t = int(input())
def op(s,k):
    s2 = list(s)
    if k < len(s):
        s3 = s2[k-1:]
        s4 = s2[0:k-1]
        if len(s3) % 2 != 0:
            s2 = s3 + s4[::-1]
        else:
            s2 = s3 + s4
        return ''.join([e for e in s2])
            
    else:
        return ''.join([e for e in s2[::-1]])
for i in range(t):
    n = int(input())
    s = input()
    s1 = s
    k1 = 1
    
    for k in range(1,len(s)+1):
        if s[k-1] <= s[0]:
            if op(s,k) < s1:
                s1 = op(s,k)
                k1 = k
    print(s1)
    print(k1)