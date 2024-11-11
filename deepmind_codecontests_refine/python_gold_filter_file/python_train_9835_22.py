n,x = map(int,input().split())
m = 0
c = 1
for i in range(n):
    l,r = map(int,input().split())
    if l-c>=x:
        c = c + ((l-c)//x)*x
        m = m + (r-c)+1
        c = r+1
    else:
        m = m + (r-c)+1
        c = c + (r-c) +1
print(m)
