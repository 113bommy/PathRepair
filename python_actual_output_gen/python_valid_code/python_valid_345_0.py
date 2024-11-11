n = int(input())
d = set()
for i in range(n):
    x = input()
    if x[0] == "i":
        d.append(x[7:])
    else :
        if(x[5:] in d) : print("yes")
        else : print("no")
