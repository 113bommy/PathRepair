
def start(n):
    a = list(range(1,n+1))
    s = []
    while len(a)>1:
        x,y = a[-1],a[-2]
        a[-2] = (x+y+1)//2
        a.pop()
        s.append("%i %i"%(x,y))
    print(a[0])
    for i in s:
        print(i)

for j in range(int(input())):
    start(int(input()))
