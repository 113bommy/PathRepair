a,b=map(int,input().split())
print('Draw' if a==b else 'Alice' if (a+13)%15<(b+13)%15 else 'Bob')
