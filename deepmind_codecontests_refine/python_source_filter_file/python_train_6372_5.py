a = list(map(int, input().split()))
f = input()
k = input().split()

d = set(f)
j = d -set(k)

for num in j:
    f = f.replace(num, "|")
print(f)

t = f.split("|")
pq = []
h = 0
for num in t:
    if num != "":
        h = h + (len(num)*(len(num)+1))//2
print(h)
        