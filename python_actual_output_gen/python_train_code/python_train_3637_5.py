n , m = map(int,input().split())
a , b = map(int,input().split())
ma = a / b
for f in range(n-1) :
    aa , bb = map(int,input().split())
    if aa / bb < ma : ma = aa / bb
print(ma)
    
