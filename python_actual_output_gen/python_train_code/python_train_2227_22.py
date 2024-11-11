a,b=map(int,input().split())
print('Draw' if a==b else 'Alice' if (a==1 and b!=1) or a>b else 'Bob')