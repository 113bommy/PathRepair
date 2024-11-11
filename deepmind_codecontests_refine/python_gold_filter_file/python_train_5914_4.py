n=int(input())
p=list(map(int,input().split()))
a = 0
for i in range(n-2):
  a += 1-((p[i] < p[i+1])^(p[i+1] < p[i+2]))
print(a)