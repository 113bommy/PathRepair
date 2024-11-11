a,b,c=map(int,input().split())
print('delicious' if b<c else 'safe' if c-b<a else 'dengerous')