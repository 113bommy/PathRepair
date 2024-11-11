a,b,c,d = map(int,input().split())
print('Yes' if (c-b)//b >= a//d else 'No')