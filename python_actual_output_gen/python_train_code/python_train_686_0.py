n=int(input())
s=input()
ans=""
for i in range(len(s)):
    ans+=chr((ord(s[i])+n)//26+64)
print(ans)
