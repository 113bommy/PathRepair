n=int(input())
for i in range(n):
    s=input()
    t=input()
    if set(s)==set(t):
        print("YES")
    else:
        print("NO")
