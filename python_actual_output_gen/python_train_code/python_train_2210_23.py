n = input()
m = input()
for i in range(len(n)-1):
    if n[i]==m[i]:
        print("0",end="")
    else:
        print("1",end="")