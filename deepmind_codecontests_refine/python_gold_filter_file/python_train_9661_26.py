n=int(input())
a=sorted(map(int, input().split()))
a1=[i for i in a if i>=0]
a2=[i for i in a if i<0]
if a1 and a2:
    print(sum(a1)-sum(a2))
    mx,mn=a1[-1], a2[0]
    for i in a1[:-1]:
        print(mn,i)
        mn-=i
    for i in a2[1:]:
        print(mx,i)
        mx-=i
    print(mx,mn)
elif not a2:
    print(sum(a1[1:])-a1[0])
    mx,mn=a1[-1], a1[0]
    for i in a1[1:-1]:
        print(mn,i)
        mn-=i
    print(mx,mn)
else:
    print(a2[-1]-sum(a2[:-1]))
    mx,mn=a2[-1], a2[0]
    for i in a2[1:-1]:
        print(mx,i)
        mx-=i
    print(mx,mn)