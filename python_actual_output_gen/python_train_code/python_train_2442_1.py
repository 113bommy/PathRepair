s = input()
q = int(ionput())
h,t = [],[]
p = 0

for i in range(q):
    c = input().split()
    if c[0] =='1':
        h,t = t,h
        p = 1-p
    else:
        if c[1] =='1':
            h.append(c[2])
        else:
            t.append(c[2])
if p ==1:
    s = s[::-1]
print("".join(h[::-1])+s+"".join(t))