n = int(input())
l = list(map(int,input().split()))
r = list(map(int, input().split()))
ans = [0] * n
flag = True
for i in range(n):
    if i - l[i] < 0 or i + r[i] >= n:
        flag = False
        # print("NO")
        break
    else:
        ans[i] = n - l[i] - r[i]

for check in range(n):
    
    les,mor = 0,0
    for element in range(n):
        if(check == element) : continue
        elif(check < element):
            if(ans[check] < ans[element]) : les += 1
        elif(check > element):
            if(ans[check] < ans[element]) : mor += 1            
    if(l[check] != les or r[check] != mor) : flag = False
    
if flag:
    print("YES")
    print(' '.join(map(str, ans)))
else:
    print("NO")