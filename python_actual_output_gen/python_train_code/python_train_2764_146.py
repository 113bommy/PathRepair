n=int(input())
l=list(map(int, input().split()))
f=0
for i in range(n):
    f=f+l[i]
print(f/3)