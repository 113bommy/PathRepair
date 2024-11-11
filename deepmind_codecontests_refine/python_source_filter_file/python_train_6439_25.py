a, b = map(int, input().split())
print('Draw' if a==b else 'Alice' if (a==1)or(b!=1 and a>b)) else 'Bob')