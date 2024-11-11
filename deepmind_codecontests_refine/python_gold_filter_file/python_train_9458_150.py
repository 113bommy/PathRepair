s = input()
str_list = ["eraser","erase","dreamer","dream"]
for e in str_list:
    s = s.replace(e,"")
ans = "YES" if s == "" else "NO"
print(ans)