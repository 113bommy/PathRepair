
n=int(input())
a=0
g=0
k = []
while(n>0):
    r1, r2=map(int, input().split(" "))
    if(g+r1-a<=500):
        g+=r1
        k.append("A")
    else:
        a+=r2
        k.append("B")
    n-=1
print(''.join(k))