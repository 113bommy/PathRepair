s=input()
for p in["eraser","erase","dreamer","dream"]:s=s.replace(p,"")
print("NO"if s else"YES")