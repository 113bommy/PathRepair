import math

def comb(a,b) :
    return ((math.factorial(a))/(math.factorial(a-b)*math.factorial(b)))

q = str(input())
q = q.split()
n = int(q[0])
m = int(q[1])
t = int(q[2])

q = comb((n+m),t)

# Subtract: there are 0 girls.
if n < t :
    q = q
else :
    q = q - comb(n,t)

# Subtract: there are b (0-3) boys.
for b in range(4):
    if m < (t-b) :
        q = q
    else :
        q = q - (comb(n,b) * comb(m,t-b))

print(int(q))
