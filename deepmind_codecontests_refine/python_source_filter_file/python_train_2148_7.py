n=int(input())
a=list(map(int,input().split()))[:n]
s=set()
for i in a[::-1]:
    if i not in s:
        s.add(i)
        t=i
print(i)
