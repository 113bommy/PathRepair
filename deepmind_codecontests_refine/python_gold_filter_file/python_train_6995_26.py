a = [4,7,44,77,47,74,444,777,477,447,474,774,747,744,447,774]
x=[]    
n = int(input())
for i in range(0,len(a)):
    if (n%a[i]) == 0:
        x.append(1)
    else:
        x.append(0)
if 1 in x:
    print("YES")
else:
    print("NO")
