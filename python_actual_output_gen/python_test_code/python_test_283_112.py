x,a,b = map(int, input().split())
print('delicious' if b <= a else 'safe' if a<x<=a+x else 'dangerous')