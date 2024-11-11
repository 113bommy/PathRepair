N = input()
l = len(N)

if n[i::] == "9"*(l-1):
    print(int(n[0])+9*(l-1))
else:
    print(int(n[0])-1+9*(l-1))