n,m,k = map(int,input().split())
o=k
print((k-1)//(2*m)+1, end = '')
k = (k-1)%(2*m)+1
print((k//2)+(k%2),end='')
if((o%2)==0):
    print('R')
else:
    print('L')