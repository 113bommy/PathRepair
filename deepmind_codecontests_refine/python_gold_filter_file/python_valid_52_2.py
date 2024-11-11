t=int(input())
for i in range(t):
    n=int(input())
    l=[int(a) for a in input().split()]
    print(max(l)+(sum(l)-max(l))/(n-1))