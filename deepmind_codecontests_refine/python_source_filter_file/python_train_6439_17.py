a,b=map(int,input().split())
a=(14-a)%13
b=(14-a)%13
print('Alice' if a<b else 'Bob' if a>b else 'Draw')