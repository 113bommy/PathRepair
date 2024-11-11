#4 10
#4 3 1 2
r = lambda: map(int,input().split())
n,k =  r()
s = list(r())
s =sorted(enumerate(s), key=lambda x:x[1])
res = []
for i,x in s:
    k-=x
    if k<0:break
    res.append(str(i))
print  (len(res))
print (' '.join(res))