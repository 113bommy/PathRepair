s=input()
lst=["eraser","erase","dreamer","dream",]
for e in lst: 
  s=s.replace(e,"")
print(s)
print("YES" if s=="" else "NO")