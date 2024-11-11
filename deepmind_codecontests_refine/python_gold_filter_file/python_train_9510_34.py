num = int(input())

mylist = list(map(int, input().split()))[:num]

small = min(mylist)

count = 0

for i in mylist:
    if i == small:
        count += 1

if count>1:
    print("Still Rozdil")
else:
    print(mylist.index(small)+1)