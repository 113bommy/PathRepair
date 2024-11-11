a,b,c,d=map(int,input().split())
print([min(b,d)-max(a,c),0][b<c])