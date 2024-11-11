f, i, t = map(int, input().split())
a=0
l =[0 for c in range(f+10)]
for p in range(f):
    s = input()
    for d in range(i):
        if s[d]=='Y':
            l[d]+=1
for p in l:
    if p>=t:
        a+=1
print(a)
#kitten