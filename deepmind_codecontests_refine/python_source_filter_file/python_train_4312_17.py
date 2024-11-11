# Link: http://codeforces.com/problemset/problem/358/A
# Love you Atreyee my life. I cannot live without you. 
n = int(input())
li = list(map(int, input().rstrip().split()))
flag = 0
for i in range(0, n - 1):
    x = min(li[i], li[i + 1])
    y = max(li[i], li[i + 1])
    
    for j in range(0, n - 1):
        a = min(li[j], li[j + 1])
        b = max(li[j], li[j + 1])

        if (a < x and x < b and b < y) or (x < a and a < y and y < b):
            flag = 1
            break

if flag == 1:
    print("YES")
else:
    print("NO")