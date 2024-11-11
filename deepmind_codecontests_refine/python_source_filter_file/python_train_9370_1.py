N=int(input())
for _ in[0]*N:
 r=[0]*N
 for i in input().split()[2:]:a[int(i)-1]=1
 print(*a)
