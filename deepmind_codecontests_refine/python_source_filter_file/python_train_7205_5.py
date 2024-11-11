a = int(input())
for i in range (a):
    b = list(map(int,input().strip().split()))
    if((sum(b)%3 == 0) and (2*max(b[:3])-(sum(b[:3])-max(b[:3])) < b[3])):
        print("YES")
    else:
        print("NO")