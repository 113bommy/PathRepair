strcode=str(input())
i=0
n=len(strcode)
strdecode=''

while i<n:
    if strcode[i]=='.':
        strdecode+='0'
        i+=1
        continue
    elif i+1<n and strcode[i]=='-' and strcode[i+1]=='.':
        strdecode+='1'
        i+=2
        continue
    elif i+1<n and strcode[i]=='-' and strcode[i+1]=='-':
        strdecode+='2'
        i+=2
        continue

print(strdecode)

