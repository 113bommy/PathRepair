a,b,c = map(int,input().split())

print('B' if abs(a-c) > abs(b-c) else 'A')