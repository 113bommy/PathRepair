a,b=map(int,input().split())
print('Impossible' if (a%3 or b%3 or (a+b)%3) else 'Possible')