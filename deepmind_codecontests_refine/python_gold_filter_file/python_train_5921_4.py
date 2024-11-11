w=int(input())
l=[i+1 for i in range(w)]
n=int(input())
for _ in range(n):
    a,b=[int(i)-1 for i in input().split(",")]
    t=l[a]
    l[a]=l[b]
    l[b]=t
for i in l:
    print(i)
