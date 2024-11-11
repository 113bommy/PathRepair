n = input()
d = input()
for i in range(len(n)):
    if n[i] == d[i]:
        print("0", end="")
    else:
        print("1", end="")