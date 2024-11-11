a,b,c,d = map(int,input().split())
print(min(min(a+b,c+d)-max(a,c),0))