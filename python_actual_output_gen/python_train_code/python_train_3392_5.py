n = int(input())
a = set(map(int,input().split()))
m = 0
for i in a:
    if i>m: m=i
s = 0
for i in a:
    s+=m-i
print(s)