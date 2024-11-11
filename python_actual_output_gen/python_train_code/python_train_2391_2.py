a,b=map(int,input().split())
if b==0 and a>0 :
    print("No solution")
else:
    print(str(b) + (a - 1) * '0')