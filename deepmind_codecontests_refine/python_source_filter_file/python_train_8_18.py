# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
# TAIWAN NUMBER ONE!!!!!!!!!!!!!!!!!!!
from sys import stdin, stdout
 
 
N = int(input())
s = input()
#arr = [int(x) for x in stdin.readline().split()]
 
eight = 0

for i in range(N):
    if s[i]=='8':
        eight += 1
        
non_eight = N-eight

#print(eight,non_eight)

res = 0

while True:
    if non_eight>=10 and eight>0:
        eight -= 1
        non_eight -= 10
        res += 1
    elif eight>0 and non_eight<=9:
        if eight+non_eight>=11:
            res += 1
            eight -= 1+(11-non_eight)
            non_eight = 0
        else:
            break
    else:
        break
    
print(res)