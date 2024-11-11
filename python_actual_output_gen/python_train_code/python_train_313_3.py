n = int(input())
a = 0
b = 0
for  i in range(n):
    s = input()
    if ('soft' == s[-4:]):
        a+=1
    else:
        b+=1
a,b = max(a,b), min(a,b)
cur1 = 1
cur2 = 0
q = 1
while (cur1 < a and cur2 < b):
    q += 1
    if (q%2):
        cur1 = (q//2+1)*(q//2 + 1) + (q//2)*(q//2)
        cur2 = (q//2+1)*(q//2)*2
    else:
        cur1 = cur2 = (q//2)*q
print(q)
    
