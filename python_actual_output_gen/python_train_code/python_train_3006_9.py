input()
a=[int(x) for x in input().split()]
b=sum(a)-2*sum(a[1::2])
print(sum(a))
print(sum(a[1::2]))
ans = [b]
for x in a:
    b = x*2-b
    ans.append(b)
print(*ans[:-1])