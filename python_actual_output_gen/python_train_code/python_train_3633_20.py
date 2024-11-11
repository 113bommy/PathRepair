s = list(input())
n = int(input())
for i in range(n):
    l,r,k = map(int, input().split())
    k%=len(s)
    if k>0:
        l-=1
        r-=1
        t = s[l:r+1]
        t=t[::-1]
        s=s[0:l]+t[k-1::-1]+t[:k-1:-1]+s[r+1:]
print(''.join(s))

