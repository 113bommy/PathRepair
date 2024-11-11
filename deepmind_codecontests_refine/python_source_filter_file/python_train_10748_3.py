t=int(input())
for i in range (t):

    s=input().split()
    n=int(s[0])
    x=int(s[1])
    s=input().split()
    for j in range(n):
        s[j]=int(s[j])
        
    l=[]
    for j in range(n):
        l.append(s[j]%2)
    e=l.count(0)
    o=l.count(1)
    if x>=o:
        if o%2==0:
            print("No")
        else:
            print("Yes")
        continue
    else:
        if (n==o and x%2==0) or n==e:
            print("No")
            continue
        else :
            print("Yes")