lvalue = [int(i) for i in input().split()]
#print(lvalue)
lkey = [i+1 for i in range(len(lvalue))]
#print(lkey)

p = dict(zip(lkey,lvalue))
#print(p)
p_new = dict(zip(p.values(),p.keys()))
result = [str(p_new[i]) for i in sorted(p_new)]
print(" ".join(result))
#print(p_new)
