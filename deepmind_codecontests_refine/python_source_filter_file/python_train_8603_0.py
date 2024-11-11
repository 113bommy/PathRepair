n , k = map(int , input().split())
d = [False for i in range(1000)]
s = input()
Mn = 1000;Mx = 0;
for char in s:
    Mn = min(Mn , ord(char))
    Mx = max(Mx , ord(char))
    d[ord(char)] = True
if(k > n):
    print(s + (k - n) * chr(Mn))
    exit()
idx = len(s) - 1
while(s[idx] == chr(Mx)):
    idx -= 1
nxtchar = 'a'
for i in range(ord(s[idx]) + 1 , ord('z') + 1):
    if(d[i]):
        nxtchar = chr(i)
        break;
print(s[:idx] + nxtchar + (k - idx - 1) * chr(Mn))

