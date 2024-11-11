k,d=map(int, input().split())

if(d==0 and k>1):
    print("No solution")
    exit()
s=str(d)+"0"*(k-1)
print(s)