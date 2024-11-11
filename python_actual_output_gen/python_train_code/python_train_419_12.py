a,b,c,d = map(int, input().split(' '))
print(a / b / (1 - ((a / b) * (c / d))))