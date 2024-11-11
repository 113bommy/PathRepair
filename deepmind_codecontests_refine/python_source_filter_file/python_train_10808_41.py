a,b,c,d = map(int,input().split())
print('Yes' if abs(a-c) <= d or abs(a-b) <= d or abs(b-c) <= d else 'No')