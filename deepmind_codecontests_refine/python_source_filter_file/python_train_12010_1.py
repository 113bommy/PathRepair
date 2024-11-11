n=int(input())
a=list(map(int,input().split()))
b=list(set(a))
b.sort()
if len(b)<3:
    print("NO")
else:
    print(b[1])