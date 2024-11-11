n=int(input())
res=0
for i in range(n):
    s=input()
    if s=="++x" or s=="x++":
        res=res+1
    else:
        res=res-1
print(res)