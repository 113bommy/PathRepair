str=input()
for i in range(len(str)-1,0,-1):
    if (str[i]>='a' and str[i]<'z')or (str[i]>='A' and str[i]<='Z'):
        if (str[i]=='a' or str[i]=='e' or str[i]=='i' or str[i]=='o' or str[i]=='u' or str[i]=='y' or str[i]=='A' or str[i]=='E' or str[i]=='I' or str[i]=='O' or str[i]=='U' or str[i]=='Y'):
            print("YES")
        else:
            print("NO")
        break