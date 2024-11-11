a=input().split(' ')
n=int(a[0])
x=int(a[1])
a=input().split(' ')
a=[int(i) for i in a]
if len(a)+sum(a)==x+1:
    print("YES")
    exit()
print("NO")
