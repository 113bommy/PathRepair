k, d = list(int(i) for i in input().split())
if d:
    print(str(d) + "0"*(k-1))
else:
    if k ==1:
        print(0)
    else:
        print("No solution")