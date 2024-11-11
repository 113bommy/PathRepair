k,d = list(map(int,input().split()))
if d == 0 and k!=1:
    print("No Solution")
else:
    print(int(str(d)+'0'*(k-1)))