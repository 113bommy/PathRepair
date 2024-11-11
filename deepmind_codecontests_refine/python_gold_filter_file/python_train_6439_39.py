a,b=((11 + int(s)) % 13 for s in input().split())
print('Alice' if a > b else 'Bob' if a < b else 'Draw')