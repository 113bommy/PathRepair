s = input()
k = int(input())

wt = [int(x) for x in input().split()]

string = "abcdefghijklmnopqrstuvwxyz"
string = list(string)
ans=0
for i in range(len(s)):
    ind = string.index(s[i])
    ans+=wt[ind]*(i+1)
maxi = max(wt)
for i in range(1,k+1):
    ans+=maxi*(k+i)
print(ans)