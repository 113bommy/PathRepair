x,a,b = [int(i) for i in input().split()]

print('delicious' if x > b else 'safe' if x > (b-a) else 'dangerous')