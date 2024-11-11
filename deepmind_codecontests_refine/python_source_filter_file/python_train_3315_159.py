a,b = map(int,input().split())
print('Possible' if a*b*(a+b)%3 else 'Impossible')