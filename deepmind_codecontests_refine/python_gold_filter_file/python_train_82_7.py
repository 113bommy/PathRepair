
def findGCD(a,b):
    if a%b == 0:
        return b
    else:
        return findGCD(b,a%b)


def judge(a,b,c,d):
    if a<b or d<b:
        return False
    elif c >= b:
        return True
    else:
        g = findGCD(b,d)
        thr = b-g+a%g
        if thr > c:
            return False
        else:
            return True
        
T = int(input())
ABCD = []
for i in range(T):
    ABCD.append(list(map(int, input().split())))
        
for a,b,c,d in ABCD:
    if judge(a,b,c,d):
        print("Yes")
    else:
        print("No")