x=int(input())
p=list(input())
k="aeuio"
for i in range(x-1):
    if p[i] in k and p[i+1] in k:p[i+1]=""
print(*p,sep="")