u,v = map(int,input().split())

if u > v and (u%2 != v%2):
    print(-1)
    exit(0)
if u == 0 and v==0:
    print(0)
    
    exit(0)
if u==v :
    print(1)
    print(u)
    exit(0)


a = (v-u)//2
if u & a :
    print(3)
    print(u,a,a)
else:
    print(2)
    print(u+a,a)
