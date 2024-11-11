a,b=map(int, input().split())
if a<=5:
    b=0
elif 6<=a<=12:
    b=b/2
print(int(b))