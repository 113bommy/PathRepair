n,m = map(int,input().split())
l = list(map(int,input().split()))
i=0
l.sort()
s = 0
while(m>0 and l[i]<0):
    s += l[i]
    m-=1
    i+=1
print(s)