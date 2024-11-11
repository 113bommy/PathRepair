k = input().split()
l = int(input().split()[0])
pp = [k[0],k[1]]
for i in range(0,l):
    p = input().split()
    if pp[-2] == p[0]:
        pp.append(p[1])
        pp.append(pp[-1])
    else:
        pp.append(pp[-2])
        pp.append(p[1])
for j in range(0, 2*l+1,2):
    print(pp[j]+' '+pp[j+1])
