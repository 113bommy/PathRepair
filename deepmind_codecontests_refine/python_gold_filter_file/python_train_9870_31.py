a,b = map(int,input().split())
if a<=5:
    b = 0
elif a<=12:
    b //= 2
print(b)