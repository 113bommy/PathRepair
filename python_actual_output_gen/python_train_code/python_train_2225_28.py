s = input()
n = len(s)
k = 10**9
if not "1" in s:
    print(0)
elif not "0" in s:
    print(n)
else:
    for i in range(n-1):
        if s[i] != s[i+1]:
            k = min(k,max(i+1,n-(i+1)))
    if k > n:
        print(n)
    else:
        print(k)
