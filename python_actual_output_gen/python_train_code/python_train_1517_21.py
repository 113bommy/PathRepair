n = int(input())
s = input()
indx = -1
for i in range(n-1):
    if s[i] > s[i+1]:
        indx = i
        break
if indx == -1:
    print(s[:n-1])
else:
    print(s[:indx+1]+s[indx+2:])