n = int(input())
if n<10:
    print(n)
else:
    x = ""
    for i in range(n):
        x = x+str(i+1)
    print(x[n])