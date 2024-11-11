t = int(input())
while t:
    t-=1
    s = input().strip()
    ans = 0
    i = 0
    while i<len(s)-1:
        if s[i]=="1"and s[i+1]=="0":
            j = i+2
            p = False
            while j<len(s)-1:
                if s[j]=="1":
                    p = True 
                    break 
                j+=1
            if p:
                ans+=(j-i-1)
            i = j
        else:
            i+=1
    print(ans)