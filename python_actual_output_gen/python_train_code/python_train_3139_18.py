a,b,c,d = map(int,input().split())
print(min(min(b,d)-max(a,c),0))