# import sys
# sys.stdin=open("input.in",'r')
# sys.stdout=open("output1.out",'w')
n, k, l, c, d, p, nl, np=map(int,input().split())
x=min(int(k*l/nl),c*d,int(p/np))
# print(int(k*l/nl),c*d,int(p/np))
print(int(x/n))