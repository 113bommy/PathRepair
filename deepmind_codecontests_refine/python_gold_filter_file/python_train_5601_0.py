n=int(input())
s=list(map(int, input().split()))
n=0
for i in s:
  n+=1/i
print(1/n)