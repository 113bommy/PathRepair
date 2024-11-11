t = int(input())
for _ in range(0,t):
    s = input()
    l,r = "",""
    ll,rr = 0,len(s)-1
    while ll < rr:
        if s[ll] == s[rr]:
            l += s[ll]
            r += s[rr]
            ll +=1
            rr -= 1
        else:
            break
    left = s[ll:rr+1]
    # print(left,"left")
    middle = ""
    for i in range(0,len(left)):
        if left[:i+1] == left[:i+1][::-1] and len(middle) < len(left[:i+1]):
            middle = left[:i+1]
    for i in range(len(left)-1,-1,-1):
        if left[i:len(left)] == left[i:len(left)][::-1] and len(middle) < len(left[i:len(left)]):
            middle = left[i:len(left)]
    print(l+middle+r[::-1])
