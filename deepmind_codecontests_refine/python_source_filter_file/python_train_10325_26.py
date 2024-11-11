n=int(input())
a=sorted(list(map(int,input().split())))
if sum(a)%2==0 and sum(a)-max(a)<=max(a):
    print("YES")
else:
    print("NO")