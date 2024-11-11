s,n = list(map(int,input().split(' ')))
c=0
l=[]
for i in range(n):
    s=input()
    l = [int(x) for x in str(s)]
    if 0 in l:
        c=c+1
    else:
        l.append(c)
        c=0
l.append(c)
l.sort()
print(l[len(l)-1])
        