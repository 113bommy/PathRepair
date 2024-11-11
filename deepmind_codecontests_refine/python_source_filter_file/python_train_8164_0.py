s = str(input())

lps = [0]*100005
dp = [0]*100005
ada = [0]*100005
tunda = [0]*100005

n = len(s)

i = 1
j = 0
lps[0] = 0

while(i < n):
    if (s[i] == s[j]):
        j += 1
        lps[i] = j
        i += 1
    elif (j == 0):
        lps[i] = 0
        i += 1
    else:
        j = lps[j-1]


for i in range(n-1,-1,-1):
    tunda[i] += 1
    dp[lps[i]] += tunda[i]
    if (i):tunda[lps[i-1]] += tunda[i]

j = n

"""
for i in range(n):
    print("SAD", i, lps[i])
"""

vector = []

while(1):
    vector.append((j,1+dp[j]))
    j = lps[j-1]
    if (j == 0): break


vector.reverse()

print(len(vector))
for i in vector:
    print(i[0], i[1])
