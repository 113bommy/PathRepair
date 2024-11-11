x=list(input())
n=len(x)
c=0
t=-1
for i in range(n-4):
    if "".join(x[i:i+4])=="bear":
        c+=(i-t)*(n-i-3)
        t=i
print(c)