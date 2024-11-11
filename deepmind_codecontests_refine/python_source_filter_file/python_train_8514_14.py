s = input()
t = input()
s_ = s[:]
cnt = 0
tlen = len(t)
ans = 0
flag = True

while cnt < tlen:
    
    num = s_.find(t[cnt])
    
    if num != -1:
        ans += (num+1)
        s_ = s_[(num+1):]
        cnt += 1
        flag = False
    else:
        if flag:
            print(-1)
            break
        ans += len(s_)
        s_ = s[:]
        flag = True
        
print(ans)