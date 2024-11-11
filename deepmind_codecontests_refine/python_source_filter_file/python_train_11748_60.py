a,b,c=map(int,input().split())
print('delicious' if c<b else 'safe' if c-b<a else 'dengerous'))