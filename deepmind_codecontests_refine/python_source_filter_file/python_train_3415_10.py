N,L=map(int, input().split())
j = 0 if L>0 else N-1 if -L>N else -L 
print(int((2*L+N-1)*N/2)-(L+j))