X,A,B=map(int,input().split())
if B-A > X: print('daangerous')
else: print('delicious' if A>B else 'safe')