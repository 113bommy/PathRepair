s = input()
if len(set(s)) == 1:
    print(s)
elif(("a" not in s)):
     if(s[:len(s) // 2] == s[len(s)//2:]):
         print(s[:len(s) // 2])
     else:
         print(":(")
else:
    left = ""
    last = s.rfind("a")
    st = ""
    for i in range(last):
        if s[i] != "a":
            left += s[i]
    right = s[last + 1:]
    flag = 0
    if len(left) > len(right) or (len(right) - len(left)) % 2 == 1:
        flag = 1
    else:
        give = (len(right) - len(left)) // 2
        left += right[:give]
        st += right[:give]
        right = right[give:]
        if left != right:
            flag = 1

    if flag:
        print(":(")
    else:
        print(s[:last] + "a" + st)
