import math
def fact(n):  
    while n % 2 == 0: 
        s.add(2)
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            s.add(i)
            n = n / i 
    if n > 2: 
        s.add(n)
input=__import__('sys').stdin.readline
p,y = map(int,input().split())
s=set()
mm = y-max(y-200,p)
for i in range(mm):
    fact(y)
    l=sorted(s)
#    print(l)
    if int(l[0])>p:
        print(y)
        exit()
    s = set()
    y-=1
print(-1)


