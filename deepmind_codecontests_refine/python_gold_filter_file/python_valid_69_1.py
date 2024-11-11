import sys
input = sys.stdin.readline

l = ["1" for _ in range(68)]
for i in range(1,68):
    l[i] = str(int(l[i-1])*2)

def comparestr(s,idx):
    i = 0
    j = 0
    same = 0
    if s == l[idx]:
        return 0
    for i in range(len(s)):
        if j >= len(l[idx]):
            break
        if s[i] == l[idx][j]:
            same += 1
            j+=1
            continue
        
    d = len(s) - same
    ins = len(l[idx]) - same
      
    return d + ins
        

for _ in range(int(input())):
    inp = input()
    ans = 100000000
    for i in range(67):
        
        temp = comparestr(inp, i)
        ans = min(ans,temp)
    print(ans-1)