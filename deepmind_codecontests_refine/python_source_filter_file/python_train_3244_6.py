def read(t=int):
    return list(map(t,input().strip().split(' ')))
t = read()[0]
while t:
    t-=1
    n =read()[0]
    a = [i%3 for i in read()]
    c = [a.count(0),a.count(1),a.count(2)]
    k = min(c[1],c[2])
    c[0]+=k
    c[1]-=k
    c[2]-=k
    print(c[0]+c[1]//3)
