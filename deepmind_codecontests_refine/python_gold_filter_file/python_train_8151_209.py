n, k, l, c, d, p, nl, np=map(int,input().split())

maxdrink=(k*l)//nl
# print(maxdrink)
maxlime=c*d
# print(maxlime)
maxsalt=p//np
# print(maxsalt)

print((min(min(maxdrink,maxlime),maxsalt))//n)