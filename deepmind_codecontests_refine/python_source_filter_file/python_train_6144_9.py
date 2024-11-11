def s(x):print(_,x,end='')
def p(u):
 if u+1:s(u);p(T[u]);p(T[u+N])
def i(u):
 if u+1:i(T[u]);s(u);i(T[u+N])
def o(u):
 if u+1:o(T[u]);o(T[u+N]);s(u)
N=int(input())
T=[0,0]*N
for _ in[0]*N:
 a,b,c=map(int,input().split())
 T[a],T[a+N]=b,c
r=(set(range(N))-set(T)).pop()
print('Preorder');p(r)
print('\nInorder');i(r)
print('\nPostorder');o(r)
print()
