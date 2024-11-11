n = int(input())
a = input().split(' ')
for i in range(n):
    a[i] = int(a[i]) - 1
    
occ = {}

for i in range(len(a)):
    if a[i] not in occ:
        occ[a[i]] = 1
    else:
        occ[a[i]] += 1

missing = []
for i in range(n):
    if i not in occ:
        missing.append(i)
        
act_missing = 0
left = [1] * n


for pos in range(n):
    if occ[a[pos]] > left[a[pos]]:
        if missing[act_missing] < occ[a[pos]] or left[a[pos]] == 0:
            occ[a[pos]] -= 1
            a[pos] = missing[act_missing]        
            act_missing += 1
        else:
            left[a[pos]] -= 1
            occ[a[pos]] -= 1
            
s = ""
for e in a:
    s += str(e + 1)
    s += ' '
    
print(len(missing))
print(s)
        
        

        