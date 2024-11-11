s = input()
L = input()
k = int(input())
l=len(s)
good = set()
string = set()
LIST = [chr(i) for i in range(97, 123)]
for i in range(26):
    if L[i] == '1':
        good.add(LIST[i])
t = [s[i] not in good for i in range(l)]
end = [0]*l
sumbad = 0
i,j=0,0
while i<l:
    if j<l:
        sumbad+=t[j]
    if sumbad>k or j==l:
        sumbad-=t[i]
        end[i]=j
        i+=1
        if sumbad>k:
            sumbad-=t[j]
            continue
    if j<l:
        j+=1
for i in range(len(s)):
    t = 0
    for j in range(i, end[i]):
        t = (t*13 + ord(s[j])-96)&1152921504606846975
        string.add(t)
print(len(string))