n=input()
b=bin(int(n, 16))[2:]
if b[-1]=='0':
    print(0)
else:
    print(1)