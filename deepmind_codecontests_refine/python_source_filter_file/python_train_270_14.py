n=int(input())
c=3
if n==10:
    print("hello")
for x in range(n):
    p = int(input())
    if p==c:
        print("NO")
        exit()
    c=6-c-p
print("YES")
