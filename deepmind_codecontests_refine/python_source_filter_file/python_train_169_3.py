n = int(input())
s = input()
l=[]
for i in range(0,len(s)):
    c=0
    for j in range(i+2, len(s),2):
        if s[i:i+2] == s[j:j+2]:
            c+=1
    l.append([s[i:i+2], c])
count=[]
for i in l:
    count.append(i[1])
ma = max(count)
for i in l:
    if ma == i[1]:
        print(i[0])
        break