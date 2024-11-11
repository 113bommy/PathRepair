n,k=input().split()
s=input()
l=list(set(list(s)))
l.sort()
d={l[i]:i for i in range(len(l))}
n=int(n)
k=int(k)
if k<=n:
    t=s[0:k]
    if d[t[k-1]]<(len(l)-1):
        print(s[0:k-1]+s[d[s[k-1]]+1])
    else:
        j=0
        for i in range(k-2, -1, -1):
            if d[t[i]]!=len(l)-1:
                j=i
                break
        print(s[0:j]+s[d[s[i]]+1]+l[0]*(k-j-1))
else:
    print(s+l[0]*(k-n))
    