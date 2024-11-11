a,b,c = map(int,input().split())

if abs(a-b) > abs(a-c):
    print('A')
else:
    print('B')