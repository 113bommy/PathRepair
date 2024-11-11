n,m,k=map(int,input().split());m-=1;n-=1
a='U'*n+'L'*m+''.join('RL'[i%2]*m+'D'for i in range(n+1))
print(len(a))
print(a)