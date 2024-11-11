k,d=map(int,input().split(" "))
if (d==0 and k>1):print("No solution")
else:print(str(d)+(k-1)*"0")