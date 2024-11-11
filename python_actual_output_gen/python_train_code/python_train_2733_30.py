my_dict = {
  "0": "",
  "1": "", 
  "2": "2", 
  "3": "3", 
  "4":"322",
  "5": "5",
  "6": "53",
  "7": "7",
  "8": "7222",
  "9": "73222"
  }

n = int(input())
f =""
for digit in input():
  f+=my_dict[digit]

print("".join(map(str, sorted(list(f), reverse=True))))