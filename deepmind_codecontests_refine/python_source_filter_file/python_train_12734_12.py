n,m=list(map(int,input().split()))
s=list(input())
d={}
l=[0]
for i in s:
    l.append(l[-1]+1+(ord(i)-ord('a')))
print(l)
for i in range(m):
    z,y=list(map(int,input().split()))
    print(l[y]-l[z-1])


