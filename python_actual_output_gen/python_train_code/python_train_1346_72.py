n,m=map(int,input().split())
q=['*'*m,'.'*(m-1)+'*','*'*m,'*'+'.'*(m-1)]
for i in range(n): print(q[i%4])

