a,b,c = map(int,input().split())
if a < c < b or b < c < a:
    print('yes')
else:
    print('no')