from sys import stdin
for _ in range(int(input())):
    n = int(input())
    a = stdin.readline().rstrip()
    b = stdin.readline().rstrip()
    x = []
    if n == 1:
        if a == b:
            print(0)
        else:
            print(1, 1)
    elif a == b:
        print(0)
    else:
        current = 0
        if a[0]=="1":
            x.append(1)
        for i in range(1,n):
            if a[i]=="1":
                if current == 0:
                    x.append(i)
                x.append(i+1)

        current = 0
        for i in range(n-1,-1,-1):
            if b[i]=="1":
                if current ==0:
                    x.append(i+1)
                    current=1
            if b[i]=="0":
                if current =="1":
                    if current == 1:
                        x.append(i+1)
                        current=0

        print(len(x), *x)

