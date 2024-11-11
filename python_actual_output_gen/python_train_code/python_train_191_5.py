n, k = [int(x) for x in input().split()]
s = input()
s = list(set([ord(x)-96 for x in s]))
if (k > 13):
    print (-1)
elif k==1 and len(s)>0:
    print (s[0])
else:
    min = sum(s)
    t = False
    for i in range(len(s)):
        j=i+1
        l=1
        w=s[i]
        m=i
        for j in range(i+1, len(s)):
            if (s[j]-1>s[m]):
                m=j
                w+=s[j]
                l+=1
                if l==k:
                    if min >= w:
                        t = True
                        min = w
                    break
    if t:
        print (min)
    else:
        print (-1)

