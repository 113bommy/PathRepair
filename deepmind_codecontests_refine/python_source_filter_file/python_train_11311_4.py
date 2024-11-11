a,b=map(int,input().split())
for _ in[0]*20:
 if b:a%=2*b
 if a:b%=2*a
print(a,b)