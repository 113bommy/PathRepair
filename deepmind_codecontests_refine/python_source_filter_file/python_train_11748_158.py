x,a,b=map(int,input().split())
print('delicious' if a>b else 'dangerous' if b>a+x+1 else 'safe')