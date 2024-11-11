n=int(input())
p=[int(x) for x in input().split()][:n]
s=0
for i in p:
    s+=i
print(s/n)