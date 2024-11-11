import collections
a = str(input())
x,y = a[0],a[1]
s = str(input())
print(s)
rank = collections.defaultdict(bool)
suit = collections.defaultdict(bool)
for i in s.split():
    # print(i)
    rank[i[0]] = True
    suit[i[1]] = True
if rank[x] == True or suit[y] == True:
    print("YES")
else:
    print("NO")
