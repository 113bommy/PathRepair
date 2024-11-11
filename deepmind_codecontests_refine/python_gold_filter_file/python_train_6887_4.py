n=int(input())
l=int(input())
c=0
f=0
g=l
if l%n!=0:
    print("NO")
else:

    while l>1:
        l=l/n
        c+=1
    if c!=0 and n**(c)==g:
        print("YES")
        print(c-1)
    else:
        print("NO")