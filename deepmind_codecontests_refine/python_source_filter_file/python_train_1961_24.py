N = input()
l = len(N)

if N[i::] == '9'*(l-1):
    print(int(N[0])+9*(l-1))
else:
    print(int(N[0])-1+9*(l-1))