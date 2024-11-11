n=int(input())
s=input()
r=s.count('R')
g=s.count('G')
b=s.count('B')
cnt=0
for i in range(n-2):
    for j in range(1, min(i+1, n-i)):
            if (s[i] != s[i-j]) and (s[i] != s[i+j]) and (s[i-j] != s[i+j]):
                cnt += 1
print(r*g*b-cnt)