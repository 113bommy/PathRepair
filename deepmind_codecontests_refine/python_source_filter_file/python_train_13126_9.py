n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
if sum(a[0:len(a)-1]) >= sum(b[0:len(b)-1]):
    print("Yes")
else:
    print("No")