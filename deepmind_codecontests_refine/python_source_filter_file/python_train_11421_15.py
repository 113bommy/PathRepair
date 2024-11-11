s=input()
while(len(s)>0):
    if s!=s[::-1]:
        break
    else:
        s=s[1:]
print(len(s),s)