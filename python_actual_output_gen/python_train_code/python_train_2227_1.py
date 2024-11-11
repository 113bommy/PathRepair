a,b=map(int,input().split())
print('Alice' if (a==1 or a>b) and b!=1 else 'Bob' if a!=b else 'Drow')
