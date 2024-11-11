n=int(input())
for i in range(n):
    l=input().split()
    print(max(int(l[0])+int(l[1]),int(l[2])+int(l[3])))