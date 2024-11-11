k,d=map(int, input().split())

if(d==0 and k>1):
    print("NO SOLUTION")
    exit()
s=str(d)+"0"*(k-1)
print(s)