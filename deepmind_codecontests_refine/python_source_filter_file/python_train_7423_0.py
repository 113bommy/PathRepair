from copy import deepcopy

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    count_0 = s.count('0')
    if count_0 % 2 != 0:
        print("NO")
    elif count_0 == 0:
        print("YES")
        print('(' * (n // 2) + ')' * (n // 2))
        print('(' * (n // 2) + ')' * (n // 2))
    elif s[0] == '0' or s[-1] == '0':
        print("NO")
    else:
        count_1 = n - count_0
        ans = ['0' for _ in range(n)]
        counter = 0
        for i in range(0, n):
            if s[i] == '1':
                if counter < count_1 // 2:
                    ans[i] = '('
                else:
                    ans[i] = ')'
                counter += 1
        ans_2 = deepcopy(ans)
        x,y='(',')'
        for i in range(0,n):
            if s[i]=='0':
                ans[i]=x
                ans_2[i]=y
            x,y=y,x
        print("YES")
        print(''.join(ans))
        print(''.join(ans_2))