n = input()
n1 = input()
for i in range(len(n)):
    if n[i] == n1[i]:
        print("0",end="")
    else:
        print("1",end="")