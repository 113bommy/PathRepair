t = int(input())

for i in range(t):
    n = int(input())
    a = input().split()
    b = input().split()
    a1 = list(map(int, a))
    b1 = list(map(int, b))
    
    for i in range(n):
        b1[i] -= a1[i]
    
    b1set = set(b1)
    
    if sum(b1set) < 0:
        print("NO")
    else:
        if len(b1set) == 1:
            print("YES")
        elif len(b1set) >= 3:
            print("NO")
        else:
            b1min = min(b1)
            if b1min != 0:
                print("NO")
            else:
                for i in range(n):
                    if b1[0] == 0:
                        b1.pop(0)
                    else:
                        break
                for i in range(n):
                    if b[-1] == 0:
                        b1.pop()
                    else:
                        break
                if "0" in b1:
                    print("NO")
                else:
                    print("YES")