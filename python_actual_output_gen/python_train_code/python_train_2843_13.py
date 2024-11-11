a=int(input())
b=int(input())
c=int(input())
d=int(input())

ans=((a|b)&(c^d))&((b&c)^(a|d))
print(ans)