X, A, B = map(int,input().split())
if A+X > B:
    print('delicious' if A > B else 'safe')
else:
    print('dangerous')