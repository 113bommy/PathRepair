from collections import deque
n = int(input())
a = deque(int(x) for x in input().split())
ans = []
temp = 0
while a:
    if a[0] > temp:
        if a[-1] > temp and a[-1] < a[0]:
            ans.append('R')
            temp = a[-1]
            a.pop()
        elif a[-1] == a[0]:
            le = a.copy()
            temp2 = le[0]
            le.popleft()
            while le and temp2 < le[0]:
                temp2 = le[0]
                le.popleft()
            ri = a.copy()
            temp3 = ri[0]
            ri.pop()
            while ri and temp3 < ri[-1]:
                temp3 = ri[-1]
                ri.pop()
            if len(a) - len(le) > len(a) - len(ri):
                ans.append('L')
                temp = a[0]
                a.popleft()
            else:
                ans.append('R')
                temp = a[-1]
                a.pop()
        else:
            ans.append('L')
            temp = a[0]
            a.popleft()
    else:
        if a[-1] > temp:
            ans.append('R')
            temp = a[-1]
            a.pop()
        else:
            break
print(len(ans))
print(''.join(ans))