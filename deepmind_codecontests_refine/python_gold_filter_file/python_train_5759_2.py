from sys import stdin, stdout
 
t = int(stdin.readline().rstrip())
# = list(map(int,stdin.readline().rstrip().split(' ')))
for _ in range(t):
    s = stdin.readline().rstrip()
    if len(set(list(s)))==1 and set(list(s))=={"a"}:
        print("NO")
    else:
        sNew = s + "a"
        sNew2 = "a" + s
        if sNew=="".join(list(reversed(sNew))):
            print("YES")
            print(sNew2)
        else:
            print("YES")
            print(sNew)

        
        