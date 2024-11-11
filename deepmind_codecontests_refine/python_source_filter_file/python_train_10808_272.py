a,b,c,d = map(int,input().split())
print('Yes' if abs(a-c) <= d or abs(a-b) and abs(b-c) else ('No'))