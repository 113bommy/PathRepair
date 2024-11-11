A,B,C,D = map(int,input().split())
L = A + B
R = C + D
print('Left' if L > R else 'Balanced' if L ==R else 'Right')
