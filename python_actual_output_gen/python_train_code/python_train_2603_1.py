n = int(input())
if n<10:
    print(n+1)
else:
    print((int(str(n)[0])+1)*10**(len(str(n))-1)-n)
    