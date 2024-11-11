x,a,b=map(int,input().split())
print('delicious'if a>b else 'safe'  if b-a<=x else 'dangerous')