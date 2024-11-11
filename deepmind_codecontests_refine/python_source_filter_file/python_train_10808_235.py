a,b,c,d=map(int,input().split())
print('Yes' if abs(a-c<=d) or (abs(b-a)<=d and abs(c-b)<=d) else 'No')
