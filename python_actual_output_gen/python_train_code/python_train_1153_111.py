a, b = map(int, input().split())
print('Impossible' if a%3!=0 and b%3!=0 and (a+b)%3==0 else 'Possible')