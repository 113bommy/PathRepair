k,d = list(map(int,input().split()))
if d == 0 and k!=1:
    print("No solution")
else:
    print(int(str(d)+'0'*(k-1)))