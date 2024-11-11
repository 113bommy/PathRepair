t=int(input())
def findandprint(s):
    for i in range(1,len(s)):
        if s[i]=='a' and s[i-1]=='b':
            print(i-1,i)
            return
        elif s[i]=='b' and s[i-1]=='a':
            print(i-1,i)
            return
while t:
    t-=1
    n=int(input())
    s=input()
    if 'ab' in s or 'ba' in s:
        findandprint(s)
    else:
        print(-1,-1)