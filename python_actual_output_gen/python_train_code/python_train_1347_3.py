n = input()
res=0
for i in range(len(n),0,-1):
    res+=(2**i if n[len(n)-i-1]=="7" else 2**(i-1))
print(res)
