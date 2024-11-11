k = int(input())
a,b = k//50, k%50

base = 49+(a if not b else a+1) 
print(50)
if b==0:
    print(" ".join(map(str, [base]*50)))
else:
    i = 50 - b
    print(" ".join(map(str, [i-1]*i + [base+i]*(50-i))))