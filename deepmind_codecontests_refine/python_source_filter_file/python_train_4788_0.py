n=int(input())
m=int(input())
s=sum(x*w for x,w in [map(int,input().split()) for _ in range(m)])
print('1\n%d %d'%([-1,1][s>0],abs(s)) if s else 0)