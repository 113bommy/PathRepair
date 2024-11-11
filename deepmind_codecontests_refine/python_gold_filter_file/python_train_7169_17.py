n=int(input())
for j in range(n):
    p=[float(i) for i in input().split()]
    if round((p[2]-p[0])*(p[7]-p[5])-(p[3]-p[1])*(p[6]-p[4]),10)==0:
        print("YES")
    else:
        print("NO")
