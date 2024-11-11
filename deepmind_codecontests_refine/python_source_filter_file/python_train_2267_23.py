x,n=map(int,input().split())
p=set(map(int,input().split()))

s=set()
for i in range(101):
    s.add(i)

s=list(s-p)

a=[abs(x-i) for i in s]
print(s[a.index(min(a))])