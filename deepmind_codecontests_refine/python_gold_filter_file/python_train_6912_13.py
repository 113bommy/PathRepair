n=int(input())
s=input()
count=0
i=(n)
while i<len(s):
    if s[i-1]==s[i-2]==s[i-3]:
        count+=1
    i+=n
print(count)