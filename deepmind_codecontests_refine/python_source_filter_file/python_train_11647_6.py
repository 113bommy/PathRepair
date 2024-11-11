import sys
import os
S = input()
lenght = len(S)
flg = 0
if lenght == 2 and S[0] == S[1]:
    print(0,1)
    sys.exit()


for i in range(lenght-2):
    if S[i] == S[i+1]:
        print(i+1,i+2)
        sys.exit()
    if S[i] == S[i+2]:
        print(i+1,i+3)
        sys.exit()
print(-1,-1)
