a,b,c,d=map(int,input().split())
s=input()
cal=0
for i in range(len(s)):
    if int(s[i])==a:
        cal += a
    elif int(s[i])==b:
        cal += b
    elif int(s[i])==c:
        cal += c
    elif int(s[i])==d:
        cal += d
print(cal)