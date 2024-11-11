import sys
input = lambda : sys.stdin.readline()
for i in range(int(input())):
    s = list(input())
    n = len(s)
    ans = -1
    nat = n
    for i in range(n//2):
        if s[i]!=s[-i-1]:
            ans = i
            break
    if ans==-1:
        print(''.join(map(str,s)))
        continue
    an = s[:ans]
    s = s[ans:n-ans]
    n-=2*ans
    d2 = [0] * n
    l = 0
    r = -1
    for i in range(n):
        if i > r:
            k = 0
        else:
            k = min(d2[l + r - i + 1], r - i + 1)
        while (i + k < n and i - k - 1 >= 0 and s[i + k] == s[i - k - 1]):
            k += 1
        d2[i] = k;
        if (i + k - 1 > r):
            l = i - k
            r = i + k - 1
    d1 = [0]*n
    l=0
    r=-1
    for i in range(n):
        if i>r:
            k = 1
        else:
            k = min (d1[l+r-i], r-i+1)
        while (i+k < n and i-k >= 0 and s[i+k] == s[i-k]):
            k+=1
        d1[i] = k;
        if (i+k-1 > r):
            l = i-k+1
            r = i+k-1
    an1 = 0
    an2 = 0
    an3= 0
    an4 = 0
    for i in range(n):
        if d1[i]==i+1:
            an1 = i+1
        if d2[i]==i:
            an2 = i
        if d1[i]==n-i:
            an3=max(d1[i],an3)
        if d2[i]==n-i:
            an4 = max(d2[i],an4)
    # print(s)
    # print(d2)
    # print(d1)
    # print(an1,an2,an3,an4)
    # print(s,an2)
    a =  max(an1*2-1,an2*2,an3*2-1,an4*2)
    if a==an1*2-1:
        ans = an+s[:an1*2-1]+an[::-1]
    elif a==2*an2:
        ans = an + s[:an2 * 2] + an[::-1]
    elif a==an3*2-1:
        ans = an + s[n-an3 * 2+1:] + an[::-1]
    else:
        ans = an + s[n - an4 * 2:] + an[::-1]
    print(''.join(map(str,ans)))
