a,b,c,d=list(map(int,input().split()))
print(max(max(b,d)-min(a,c),0))