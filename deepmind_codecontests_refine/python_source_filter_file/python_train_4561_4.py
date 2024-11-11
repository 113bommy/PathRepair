s=input()
s.replace("BC","D").replace("B","C")
l=[i for i in split("C") if len(i) !=0]
cnt=0
for line in l:
  dcnt =0 
  for ch in reversed(line):
    if ch = "D":
      dcnt+=1
    else:
      cnt+=dcnt

print(cnt)