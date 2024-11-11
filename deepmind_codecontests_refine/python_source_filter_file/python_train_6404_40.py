m=str(input())
n=str(input())
l=len(m)
w=""
for i in range(l):
    a=m[i]
    b=n[i]
    if a!=b:
        w=w+"1"
    else:
        w=w+"0"
print(int(w))