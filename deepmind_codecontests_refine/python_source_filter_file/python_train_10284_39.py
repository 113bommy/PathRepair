k = int(input())
a, b = map(int, input().split())

if a <= (b / k) * k: print('OK')
else: print('NG') 
