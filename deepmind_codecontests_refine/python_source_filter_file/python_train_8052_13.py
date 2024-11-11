#ismailmoussi
n=int(input())
lfou9=int(input())
input()
for i in range(n-1):
    li=list(map(int,input().split()))
    if lfou9 in li or 7-lfou9 in li:
        print("NO")
        None

print("YES")