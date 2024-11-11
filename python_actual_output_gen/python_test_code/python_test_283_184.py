X,A,B=map(int,input().split())
if B-A >= X+1: print('dangerous')
else: print('delicious' if A>B else 'safe')