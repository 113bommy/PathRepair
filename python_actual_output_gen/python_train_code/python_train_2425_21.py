a,b=map(int,input().split())
if not a:
 if not b:print(0)
 else:print('Impossible')
else:print(max(a,b),a+b-bool(b))