x,a,b=map(int,input().split())
print('delicious' if 0<a-b else 'dangerous' if x>a-b else 'safe')