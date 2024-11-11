import sys

n,a,b,c = map(int,input().split())

abc = {"A":a,"B":b,"C":c}

s = [input() for _ in range(n)]

ans = [None]*n
i = 0
while i <n:
    x = s[i][0]
    y = s[i][1]
    if abc[x] == 0 and abc[y] ==0:
        print("No")
        sys.exit()
    elif abc[x] == 1 and abc[y] ==1 and i<n-1:
        if s[i] == s[i+1]:
            ans[i] = x
            ans[i+1] = y
            i += 1
        elif x in s[i+1]:
            ans[i] = x
            abc[x] += 1
            abc[y] -= 1
        else:
            ans[i] = y
            abc[x] -= 1
            abc[y] += 1
    else:
        if abc[x]<=abc[y]:
            ans[i] = x
            abc[x] += 1
            abc[y] -= 1
        else:
            ans[i] = y
            abc[x] -= 1
            abc[y] += 1
    i += 1
    
print("Yes")
print("\n".join(ans))