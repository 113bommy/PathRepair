import collections

s = input()
n = len(s)
if n<26:
    print(-1)
    exit()
d = [0]*26
for i in range(25):
    if s[i]!='?':
        d[ord(s[i])-ord('A')]+=1

def check():
    return all(d[i]<=1 for i in range(26))

b = False
for i in range(25,n):
    if s[i]!='?':
        d[ord(s[i])-ord('A')] += 1
    if i>=26:
        if s[i-26]!='?':
            d[ord(s[i-26])-ord('A')] -= 1
    if check():
        for j in range(n):
            if s[j]!='?':
                print(s[j],end="")
            else:
                if j<i-25 or j>i:
                    print('A',end="")
                else:
                    for k in range(26):
                        if d[k]==0:
                            print(chr(ord('A')+k),end="")
                            d[k]=1
                            break
        exit()
print(-1)