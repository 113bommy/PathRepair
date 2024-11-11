s=input()
cnt=s.count("VK")
s1=s.replace("VK","*")
if "VV" in s1 or "VK" in s1:
    cnt+=1
print(cnt)