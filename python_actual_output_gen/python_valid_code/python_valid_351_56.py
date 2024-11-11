count = 0
a = input().lower()
b = input().lower()
l = len(a)
for i in range(l): 
    if a[i] == b[i] :
        count += 1
        continue
    else:
        if a[i] > b[i]:
            print("-1")
            break
        
        elif a[i] < b[i]:
            print("-1")
            break
                
if count == l:
    print("0")