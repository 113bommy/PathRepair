from collections import Counter
m = int(input())
c=1
old=0
l=[]
for i in range(0,m):
    hr, mint = map(int, input().split())
    val = 10*hr+mint
    l.append(val)

cnt = Counter(l)
a=cnt.most_common(1)
print(a[0][1])