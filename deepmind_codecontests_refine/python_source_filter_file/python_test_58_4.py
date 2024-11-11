t = int(input())

for _ in range(t):
    n = int(input())
    r1 = input()
    r2 = input()

    good = False 
    for i in range(n):
        if r1[i] == '1' and r2[i] == '1':
            good = True 
            break 

    if good:
        print("YES")

    else:
        print("NO")            
