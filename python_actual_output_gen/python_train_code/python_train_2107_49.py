s=input()
for i in range(len(s)-7):
    ss=s[i:i+7]
    if(ss=="0000000" or ss=="1111111"):
        print("YES")
        exit()
print("NO")