n, k = map(int, input().split())
a=input().split()
sum=0
for i in a:
  sum+=int(int(i)>=k)
print(sum)