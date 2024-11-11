import sys

n = int(sys.stdin.readline())
s = str(sys.stdin.readline())[:-1].split('S')

single = False
mx = len(s[0])
blocks = 0
canConc = False
if mx>0:
    blocks+=1
for i in range(1,len(s)):
    tmpSum = len(s[i-1])+len(s[i])    
    if len(s[i])>0:        
        blocks+=1
        if len(s[i-1])>0:
            canConc = True
    #print(tmpSum)
    if tmpSum>mx:
        mx = tmpSum
if blocks>2 and canConc:
    mx+=1
elif canConc==False:
    if blocks == 2:
        mx+=1
print(mx)
'''
last = 'S'
cubs = 0
for i in range(n):
    if last != s[i]:
        if s[i]=='G':
            cubs=1
        else:
            parts.append(
        last = s[i]
'''
