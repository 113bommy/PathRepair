t = int(input())
for _ in range(t):
    s=input()
    res= s[:2]
    for i in range(2,len(s)):
        if i%2!=0:
            res=res+s[i]
    print(s)