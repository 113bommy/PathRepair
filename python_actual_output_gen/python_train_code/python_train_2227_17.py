a,b = map(int, input().split())
print('Draw' if a==b else 'Alice' if (a+12)%14>(a+12)%14 else 'Bob')