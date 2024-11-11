n = int(input())

lst_str = []
for i in range(n):
    string = input()
    lst_str.append(string)
    
lst2 = sorted(lst_str, key=len)

for a in range(0, len(lst2)):
    if a == len(lst2) - 1:
        continue
    if lst2[a] not in lst2[a+1]:
        print("NO")
        break
        
else:
    print("Yes")
    for i in lst_str:
        print(i)