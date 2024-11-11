n = eval(input())
c = input()
i =0
count =0
temp=0
for j in range(n):
    if c[j] == "8":
        i+=1
if i ==0:
    print(0)
else:
    while count < i and temp+11<=n:
       temp+=11
       count+=1
    print(count)
