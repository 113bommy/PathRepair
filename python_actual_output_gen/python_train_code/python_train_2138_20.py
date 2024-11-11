n=int(input())
a=[int(n) for n in input().split(" ")]
if min(a)>1:
    print(min(a)-1)
else:
    print(-1)
