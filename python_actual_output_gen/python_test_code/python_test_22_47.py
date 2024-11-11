n, k = map(int, input().split())
y = list(map(int, input().split()))
a = []
set = 0
for i in y:
    if i <= (5-k):
        a.append(i)
    if len(a)%3==0:
        set+=1
print(set)
