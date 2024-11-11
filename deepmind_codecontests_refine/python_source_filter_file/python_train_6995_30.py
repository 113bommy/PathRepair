import sys
s=input()
def lucky(s):
    for i in range(len(s)):
        if s[i]=='4' or s[i]=='7':
            continue
        else:
            return False
    return True
if lucky(s):
    print('YES')
    sys.exit(0)
else:
    for i in range(4,int(s)//2):
        if lucky(str(i)):
            if int(s)%4==0:
                print("YES")
                sys.exit(0)
print('NO')
