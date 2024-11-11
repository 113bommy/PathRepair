a,b,c,d=map(int,input().split())
print(0 if b<=c else min(b,d)-max(a,c))