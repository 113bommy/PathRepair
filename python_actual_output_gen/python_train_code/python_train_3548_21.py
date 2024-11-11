n=int(input())
a=[int(x) for x in input().split()]
if sum(a)%2==0 and sum(a[:len(a)-1])>=a[len(a)-1]:
    print("YES")
else:
    print("NO")
