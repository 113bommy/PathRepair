a,b,c,d = map(int,input().split())
print(max(min(a+b,c+d)-max(a,c),0))