n, s = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
if sum(a)-a[-1]>s:
    print("NO")
else:
    print("YES")