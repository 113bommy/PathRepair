n = int(input())
s = list(input())
s = "".join(s).split()
lst = []
for i in s:
   lst.append("".join(list(sorted(set(list(i))))))
print(len(list(set(lst))))
    
