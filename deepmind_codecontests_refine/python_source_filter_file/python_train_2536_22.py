s = input();
if s[0] == "h":
    ans = "http://";
    for i in range(4, len(s)):
        if s[i] == "r" and s[i+1] == "u":
            ans += s[4:i] + "." + s[i:i+2];
            if i+1 < len(s)-1:
                ans += "/" + s[i+2:];
                break;

else:
    ans = "ftp://";
    for i in range(3, len(s)):
        if s[i] == "r" and s[i+1] == "u":
            ans += s[3:i] + "." + s[i:i+2];
            if i+1 < len(s)-1:
                ans += "/" + s[i+2:];
                break;
print(ans)


