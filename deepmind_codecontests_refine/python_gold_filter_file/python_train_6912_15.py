n=int(input())
f=input()
list(f)
out=0
for i in range(n,len(f),n):
    if(f[i-1]==f[i-2] and f[i-2] == f[i-3]):
        out=out+1
print(out)