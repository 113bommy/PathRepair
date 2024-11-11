s=input()

vowel=['a','e','o','i','u']
isans=True
state=0

if s[0]=='n':
    state =0
elif s[0] in vowel:
    state =1
else:
    state =2

if len(s)==1:
    if s[0] not in vowel and s[0] !='n':
        isans=False

if s[len(s)-1] not in vowel and s[0] !='n':
    isans=False


for i in range(0,len(s)):
    if(i==0):
        continue
    else:
        if(state==2):
            if(s[i] not in vowel):
                isans=False
        if s[i]=='n':
            state =0
        elif s[i] in vowel:
            state =1
        else:
            state =2

if isans:
    print("YES")
else:
    print("NO")
