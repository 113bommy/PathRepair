N = int(input())
A = list(map(int,input().split()))
l = [0]*N
for i in A:
  l[i-1] += 1
print(l,sep="\n")