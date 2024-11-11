a=list(input())
b=list(input())
c=len(a)*['0']
for i in range(0,len(a)):
    if a[i]!=b[i]:
        c[i]='1'
print(int(''.join(c)))
