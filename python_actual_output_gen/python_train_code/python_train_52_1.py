s=input();s=s.lower();s=(' '.join(s)).split();n=int(input())
for i in range(0,len(s)):
    if n+96>ord(s[i]):
        s[i]=chr(ord(s[i])-32)
for j in range(0,len(s)):
    print(s[j],end='')