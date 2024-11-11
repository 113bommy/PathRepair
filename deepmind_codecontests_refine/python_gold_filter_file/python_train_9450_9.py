n, k = map(int, input().split())
A=list(map(int, input().split()))

c=1
path=[]
d={}
l=0
while l<=k:
    if c in d:
        p=d[c]
        #print(p, path)
        pattern_l = l-p
        k-=((k-p)//pattern_l)*pattern_l
    path.append(c)
    l+=1
    d[c]=l-1
    c=A[c-1]
print(path[k])
