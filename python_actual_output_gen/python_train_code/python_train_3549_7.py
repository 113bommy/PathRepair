x=int(input())
for __ in range(x):
    n=int(input())
    a=input()
    b=input()
    c=0
    l=[]
    for i in range(n):
        if a[i]!=b[i]:
            c+=1
            l.append(i)
    if c==2:
        if b[l[0]]==b[l[1]] and a[l[0]]==a[l[0]]:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")