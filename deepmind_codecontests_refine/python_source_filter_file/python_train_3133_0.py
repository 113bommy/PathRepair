a = list(input())
b = list(input())
if len(a) < len(b): a,b = b,a
j = len(b)-1
ans = 0
for i in range(len(a)-1,-1,-1):
    if a[i] == b[j]: ans += 1; j-=1
    else:
        print(len(a)-2*ans+len(b)); exit()
if j != -1: print(abs(len(b)-len(a)))
else: print(0)