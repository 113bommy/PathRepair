import sys
S = input().strip()

for i in range(3,len(S)+1):
    for j in range(0,len(S)+1-i):
        s = S[j:j+i]
        for k in set(s):
            if s.count(k)*2 > len(s):
                print(j+1,j+i)
                sys.exit(0)

print(-1,-1)
