input()
s=input()
a=""
t=[a,a,"2","3","223","5","53","7","7222","7333"]
for c in s:
    a+=t[int(c)]
print(''.join(sorted(a)[::-1]))
