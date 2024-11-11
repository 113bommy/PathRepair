first_xor = [0]
for i in range(1, 3*10**5+1):
    first_xor.append(first_xor[-1]^i)
    
def process(a, b):
    if b==first_xor[a-1]:
        return a
    elif b^first_xor[a-1]==a:
        return a+2
    else:
        return a+1
    
t = int(input())
for i in range(t):
    a, b = [int(x) for x in input().split()]
    print(process(a, b))