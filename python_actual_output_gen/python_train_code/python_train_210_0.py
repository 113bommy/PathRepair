n,x,y=map(int,input().split())
def f(a,x,y):return(a*x+x+y-1)/(x+y)
for _ in[0]*n:n=int(input());r=f(n,x,y)*y-f(n,y,x)*x;print(['Both','Vova','Vanya'][(r>0)+(r<0)*2])