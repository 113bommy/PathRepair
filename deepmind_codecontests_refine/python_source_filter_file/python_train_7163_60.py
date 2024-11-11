n, a, b = map(int, input().split(' '))
print(f'{min(a,b)} {min(0,abs(a+b-n))}')
