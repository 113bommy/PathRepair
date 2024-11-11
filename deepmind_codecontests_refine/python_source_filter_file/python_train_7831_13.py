T=int(input())
for i in range(T):
    t=input()
    s=t[0]
    j=0
    if "0" not in s or "1" not in s:
        print(t)
        continue
    while j<len(t):
        if j==len(t)-1:
            break
        if t[j]==t[j+1] and t[j]=="1":
            s+="0"+t[j+1]
            j+=1
        elif t[j]==t[j+1] and t[j]=="0":
            s+="1"+t[j+1]
            j+=1
        else:
            s+=t[j+1]
            j+=1
    print(s)