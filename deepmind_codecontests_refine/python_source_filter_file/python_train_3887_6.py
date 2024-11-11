n = int(input())
a=list(map(int,input().split()))
a.sort()
a.reverse()
s = sum(a)
d=0
c=0
for i in a:
    c+=1
    d+=i
    s-=d
    if(d>s):
        print(c)
        break
