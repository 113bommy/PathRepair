Dict = {2:2,3:3,4:322,5:5,6:53,7:7,8:7222,9:9}
n = int(input())
arr = [int(i) for i in input()]
s = ""
for i in arr:
    if i != 1 and i!=0:
        s+=(str(Dict[i]))
sor = sorted(s)
s = "".join(sor)
s = s[::-1]
print(int(s))
