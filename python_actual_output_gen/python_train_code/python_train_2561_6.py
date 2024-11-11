n=int(input())
for i in range(n):
    s=input()
    p=""
    for i in range(0,len(s),2):
        p+=s[i]
    if len(s)%2:
        p+=s[-1]
    print(p)
        