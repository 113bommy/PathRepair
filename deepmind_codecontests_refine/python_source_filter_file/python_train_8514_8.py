s = input()
t = input()

s_ = s[:]

ti = 0
ans = 0
flag = True

while ti < len(t):
    si = s_.find(t[ti])
    
    if si != -1:
        ans += si + 1
        s_ = s_[si+1:]
        ti += 1
        flag = False
    else:
        if flag:
            print(-1)
            break
        ans += len(s_)
        s_ = s[:]
        flag = True
        
print(ans)