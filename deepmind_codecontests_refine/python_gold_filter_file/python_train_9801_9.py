n=int(input())
vs=sorted([int(x) for x in input().split(' ')])
s=sum(vs)
c=int(input())
cs=[int(x) for x in input().split(' ')]
for i in range(c):
    print(str(s-vs[n-cs[i]]))