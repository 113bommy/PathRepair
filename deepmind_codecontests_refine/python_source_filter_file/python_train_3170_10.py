n = int(input())
d=dict()
for i in range(n):
    a=input()
    if a not in d.keys():
        d[a]=1
    else:
        d[a]+=1
print(max(d.keys()))