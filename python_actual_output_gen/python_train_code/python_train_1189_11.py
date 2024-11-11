from sys import stdin
#stdin = open ( 'input.txt' , 'r')
input = lambda : stdin.readline()


ii = lambda  :  int  ( input() )
mi = lambda  :  map  ( int, input().split() )
li = lambda  :  list ( map ( int, input().split() ) )

n,k=mi()
s=input().strip()
key='1'+'0'*(n-1)
s=list(s)
key=list(key)
if len(s)==1:print('0' if k>0 else s)
else:
    for i in range(n):
        if not k:break
        if s[i]!=key[i]:
            s[i]=key[i]
            k-=1
    print(*s,sep='')