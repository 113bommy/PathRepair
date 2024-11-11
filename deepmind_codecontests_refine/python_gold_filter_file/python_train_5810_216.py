a,b=map(int,input().split())
print('IMPOSSIBLE' if (a+b)%2!=0 else (a+b)//2)