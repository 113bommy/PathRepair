X,A,B= map(int,input().split())
print('dngerous' if X<B-A else 'safe' if B>A else'delicious')