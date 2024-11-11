a,b=map(int,input().split())
print('Draw' if a==b else 'Alice' if b!=1 and (a==1 or a>b) else 'Bob')