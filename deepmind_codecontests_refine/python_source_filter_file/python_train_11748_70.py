X,A,B = map(int,input().split())

print('delicious' if B <= A else 'safe' if A+B <= X else 'dangerous')