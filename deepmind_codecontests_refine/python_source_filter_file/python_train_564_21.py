# import sys
# input = sys.stdin.buffer.readline


s = input()
t = input()
if len(s)<len(t):
    print("need tree")
else:
    sCnt = [0]*26
    tCnt = [0]*26
    for c in s:
        sCnt[ord(c)-ord('a')]+=1
    for c in t:
        tCnt[ord(c)-ord('a')]+=1
    extra = 0
    flag=True
    for i in range(26):
        if tCnt[i]>sCnt[i]:
            flag=False
            break
        else:
            extra+=sCnt[i]-tCnt[i]
    i=0
    j=0
    while i<len(s) and j<len(t):
        if s[i]==t[j]:
            i+=1
            j+=1
        else:
            i+=1
    isAuto=True
    if j<len(t):
        isAuto=False
    if not flag:
        print("need tree")
    elif extra==0:
        print("array")
    elif isAuto:
        print("automation")
    else:
        print("both")
        
    