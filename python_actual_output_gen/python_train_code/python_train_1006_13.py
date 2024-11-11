T=int(input())
for i in range (T):
    s=input()
    if len(s)>=10:
        s=s[0]+str(len(s)-2)+s[-1]
    print(s)