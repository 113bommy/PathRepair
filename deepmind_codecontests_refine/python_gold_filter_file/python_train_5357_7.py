# http://codeforces.com/problemset/problem/469/B

I = lambda:map(int, input().split())
p,q,l,r = I()
fixed = []
flexible = []

for _ in range(p):
    a,b = I()
    # storing all numbers within that range
    fixed+=[x for x in range(a, b+1)]
    #print("fixed: ", fixed)

for _ in range(q):
    a,b = I()
    # storing all nos within that range
    flexible += [x for x in range(a, b+1)]
    #print("flexible: ", flexible)

fixed = set(fixed)
#print("fixed: ", fixed)
count = 0

for t in range(l, r+1):
    flexiblet = set([x+t for x in flexible])
    #print("flexiblet: ",flexiblet)
    if len(fixed & flexiblet) > 0: # taking intersection of two sets
        #print("len: ",(fixed & flexiblet) )
        count+= 1
        #print("count: ",count)
print(count )
