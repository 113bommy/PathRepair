str=input()
cnt_a=1
cnt_b=cnt_c=0
flag=0
for i in range(1,len(str)):
    if str[i]=='a' and str[i-1]=='a':
        cnt_a+=1
    elif str[i]=='b' and (str[i-1]=='b' or (str[i-1]=='a' and cnt_b==0)):
        cnt_b+=1
    elif str[i]=='c' and (str[i-1]=='c' or (str[i-1]=='b' and cnt_c==0)):
        cnt_c+=1
    else:
        print("NO")
        exit()
if str[0]=='a' and (cnt_c==cnt_a or cnt_c==cnt_b) and cnt_b>0:
    print("YES")
else:
    print("NO")
